#include "mmix.h"

int main(int argc, char *argv[])
{
    Memory mem = memory_new();
    uint8_t *ptr;
    ptr = memory_get(&mem, 0x0123456789ab0000);
    ptr = memory_get(&mem, 0x00);
    ptr = memory_get(&mem, 0x01);
    ptr = memory_get(&mem, 0x0123456789ab0000);
    ptr = memory_get(&mem, 0x0123012301230000);
    ptr = memory_get(&mem, 0x0123456789010000);

    memory_debug_nodes(&mem);
    return 0;
}
