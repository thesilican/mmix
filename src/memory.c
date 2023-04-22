#include "mmix.h"

// Constructs a new memory object with one root node and 0 allocated pages
Memory memory_new()
{
    Memory memory;

    // Allocate nodes
    memory.nodes = malloc(sizeof(MemoryPageNode) * MEMORY_PAGE_MAX_NODES);
    if (memory.nodes == NULL)
    {
        fprintf(stderr, "malloc failed");
        exit(1);
    }
    // Set every entry of first node to 0
    for (int i = 0; i < 256; i++)
    {
        memory.nodes[0].children[i] = 0;
    }
    memory.node_count = 1;

    // Allocate pages memory
    memory.pages = malloc(65536);
    if (memory.pages == NULL)
    {
        fprintf(stderr, "malloc failed");
        exit(1);
    }
    memory.page_count = 0;
    memory.page_capacity = 1;
    return memory;
}

static size_t memory_push_node(Memory *memory)
{
    size_t node_count = memory->node_count;
    if (node_count == MEMORY_PAGE_MAX_NODES)
    {
        fprintf(stderr, "memory page nodes exceeded max node count");
        exit(1);
    }
    // Set every entry of new node children to 0
    for (int i = 0; i < 256; i++)
    {
        memory->nodes[node_count].children[i] = 0;
    }
    memory->node_count++;
    return node_count;
}

static size_t memory_push_page(Memory *memory)
{
    size_t page_count = memory->page_count;
    if (page_count == memory->page_capacity)
    {
        // Realloc!
        memory->page_capacity *= 2;
        uint8_t *new_pages = malloc(memory->page_capacity * 65536);
        if (new_pages == NULL)
        {
            fprintf(stderr, "malloc failed");
            exit(1);
        }
        memcpy(new_pages, memory->pages, page_count * 65536);
        free(memory->pages);
        memory->pages = new_pages;
    }
    // Zero the memory
    uint8_t *ptr = memory->pages + (page_count * 65536);
    memset(ptr, 0, 65536);
    memory->page_count++;
    return page_count;
}

// Returns the page index for a given address, creating the page
// and any intermediary tree nodes along the way
static size_t memory_probe(Memory *memory, uint64_t address)
{
    size_t node_idx = 0;
    for (int i = 0; i < 6; i++)
    {
        size_t child_idx = (address >> ((7 - i) * 8)) % 256;
        MemoryPageNode *node = &memory->nodes[node_idx];
        node_idx = node->children[child_idx];
        if (node_idx == 0)
        {
            node_idx = memory_push_node(memory);
            node->children[child_idx] = node_idx;
        }
    }
    MemoryPageNode *node = &memory->nodes[node_idx];
    if (node->children[0] == 0)
    {
        node->children[0] = 1;
        node->children[1] = memory_push_page(memory);
    }
    return node->children[1];
}

// Returns a pointer to the byte at a specified address
uint8_t *memory_get(Memory *memory, uint64_t address)
{
    size_t page_idx = memory_probe(memory, address);
    uint8_t *ptr = memory->pages + (page_idx * 65536) + (address % 65536);
    return ptr;
}

// Free memory allocated by object
void memory_destroy(Memory *memory)
{
    free(memory->nodes);
    memory->nodes = NULL;
    free(memory->pages);
    memory->pages = NULL;
}

static void memory_debug_nodes_rec(MemoryPageNode *nodes, size_t idx, size_t depth)
{
    if (depth == 6)
    {
        if (nodes[idx].children[0])
        {
            for (int i = 0; i < depth; i++)
            {
                printf("  ");
            }
            printf("> %zu\n", nodes[idx].children[1]);
        }
        else
        {
            for (int i = 0; i < depth; i++)
            {
                printf("  ");
            }
            printf("Empty\n");
        }
    }
    else
    {
        for (int i = 0; i < 256; i++)
        {
            if (nodes[idx].children[i])
            {
                for (int i = 0; i < depth; i++)
                {
                    printf("  ");
                }
                printf("%02x\n", i);
                memory_debug_nodes_rec(nodes, nodes[idx].children[i], depth + 1);
            }
        }
    }
}

// Prints out the nodes that specify the memory layout
void memory_debug_nodes(Memory *memory)
{
    memory_debug_nodes_rec(memory->nodes, 0, 0);
}

uint8_t memory_get_byte(Memory *memory, uint64_t address)
{
    return *memory_get(memory, address);
}

uint16_t memory_get_wyde(Memory *memory, uint64_t address)
{
    address &= ~0b1;
    assert(address % 2 == 0);
    uint16_t value = 0;
    for (int i = 0; i < 2; i++)
    {
        uint16_t byte = *memory_get(memory, address + i);
        value |= byte << ((1 - i) * 8);
    }
    return value;
}

uint32_t memory_get_tetra(Memory *memory, uint64_t address)
{
    address &= ~0b11;
    assert(address % 4 == 0);
    uint32_t value = 0;
    for (int i = 0; i < 4; i++)
    {
        uint32_t byte = *memory_get(memory, address + i);
        value |= byte << ((3 - i) * 8);
    }
    return value;
}

uint64_t memory_get_octa(Memory *memory, uint64_t address)
{
    address &= ~0b111;
    assert(address % 8 == 0);
    uint64_t value = 0;
    for (int i = 0; i < 8; i++)
    {
        uint64_t byte = *memory_get(memory, address + i);
        value |= byte << ((7 - i) * 8);
    }
    return value;
}

void memory_set_byte(Memory *memory, uint64_t address, uint8_t value)
{
    *memory_get(memory, address) = value;
}

void memory_set_wyde(Memory *memory, uint64_t address, uint16_t value)
{
    address &= ~0b1;
    assert(address % 2 == 0);
    for (int i = 0; i < 2; i++)
    {
        *memory_get(memory, address + i) = value >> ((1 - i) * 8);
    }
}

void memory_set_tetra(Memory *memory, uint64_t address, uint32_t value)
{
    address &= ~0b11;
    assert(address % 4 == 0);
    for (int i = 0; i < 4; i++)
    {
        *memory_get(memory, address + i) = value >> ((3 - i) * 8);
    }
}

void memory_set_octa(Memory *memory, uint64_t address, uint64_t value)
{
    address &= ~0b111;
    assert(address % 8 == 0);
    for (int i = 0; i < 8; i++)
    {
        *memory_get(memory, address + i) = value >> ((7 - i) * 8);
    }
}