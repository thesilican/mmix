#ifndef MMIX_H
#define MMIX_H
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Computer Computer;
typedef struct Memory Memory;
typedef struct MemoryPageNode MemoryPageNode;
typedef struct Op Op;

#define MEMORY_PAGE_MAX_NODES 65536

struct MemoryPageNode {
    // For leaf node, children[1] contains page index,
    // children[0] is set to 1 if page is allocated otherwise 0
    // For other nodes, children[i] contains index of next node
    // or 0 if there is no next node (conveniently index 0 is the root node,
    // which is never referenced)
    size_t children[256];
};

// There is 2^64 bytes of addressable memory
// Memory is stored in pages that are 2^16 bytes each, a tree of
// nodes maps the remaining 2^48 address space to its corresponding page. Each
// node narrows the search space by a factor of 2^8
struct Memory {
    MemoryPageNode *nodes;
    size_t node_count;
    uint8_t *pages;
    size_t page_count;
    size_t page_capacity;
};

Memory memory_new();
uint8_t *memory_get(Memory *memory, uint64_t address);
uint8_t memory_get_byte(Memory *memory, uint64_t address);
uint16_t memory_get_wyde(Memory *memory, uint64_t address);
uint32_t memory_get_tetra(Memory *memory, uint64_t address);
uint64_t memory_get_octa(Memory *memory, uint64_t address);
void memory_set_byte(Memory *memory, uint64_t address, uint8_t value);
void memory_set_wyde(Memory *memory, uint64_t address, uint16_t value);
void memory_set_tetra(Memory *memory, uint64_t address, uint32_t value);
void memory_set_octa(Memory *memory, uint64_t address, uint64_t value);
void memory_debug_nodes(Memory *memory);
void memory_destroy(Memory *memory);

struct Computer {
    uint64_t *reg;
    Memory memory;
};

Computer computer_new();
uint64_t *computer_greg(Computer *computer, uint8_t reg);
uint64_t *computer_sreg(Computer *computer, uint8_t reg);
uint64_t computer_get_greg(Computer *computer, uint8_t reg);
uint64_t computer_get_sreg(Computer *computer, uint8_t reg);
void computer_set_greg(Computer *computer, uint8_t reg, uint64_t value);
void computer_set_sreg(Computer *computer, uint8_t reg, uint64_t value);
void computer_destroy(Computer *computer);

struct Op {
    uint8_t op;
    uint8_t x;
    uint8_t y;
    uint8_t z;
};

Op op_decode(uint32_t tetra);
uint32_t op_encode(Op op);
void op_exec(Computer *computer, Op op);

void test_ops();
void tests_run();

#endif
