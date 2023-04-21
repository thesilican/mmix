#include "mmix.h"

int main(int argc, char *argv[])
{
    // Memory mem = memory_new();
    // uint8_t *ptr;
    // ptr = memory_get(&mem, 0x0123456789ab0000);
    // ptr = memory_get(&mem, 0x00);
    // ptr = memory_get(&mem, 0x01);
    // ptr = memory_get(&mem, 0x0123456789ab0000);
    // ptr = memory_get(&mem, 0x0123012301230000);
    // ptr = memory_get(&mem, 0x0123456789010000);

    // memory_debug_nodes(&mem);
    // printf("%lu\n", sizeof(Computer));
    Computer computer = computer_new();
    uint64_t greg0 = computer_get_greg(&computer, 0);
    printf("%016llx\n", greg0);
    computer_destroy(&computer);
    return 0;
}
