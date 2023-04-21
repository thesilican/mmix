#include "mmix.h"

Computer computer_new()
{
    Computer computer;
    for (int i = 0; i < 256; i++)
    {
        computer.greg[i] = 0;
    }
    for (int i = 0; i < 32; i++)
    {
        computer.sreg[i] = 0;
    }
    computer.memory = memory_new();
}

void computer_destroy(Computer *computer)
{
    memory_destroy(&computer->memory);
}