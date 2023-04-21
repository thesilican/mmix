#include "mmix.h"

Computer computer_new()
{
    Computer computer;
    // Allocate registers in a single contiguous block
    uint64_t *reg = malloc(sizeof(uint64_t) * (256 + 32));
    if (reg == NULL)
    {
        fprintf(stderr, "malloc failed");
        exit(1);
    }
    for (int i = 0; i < (256 + 32); i++)
    {
        reg[i] = 0;
    }
    computer.reg = reg;
    computer.memory = memory_new();
    return computer;
}

uint64_t *computer_greg(Computer *computer, uint8_t reg)
{
    return computer->reg + reg;
}
uint64_t computer_get_greg(Computer *computer, uint8_t reg)
{
    return *computer_greg(computer, reg);
}
void computer_set_greg(Computer *computer, uint8_t reg, uint64_t value)
{
    *computer_greg(computer, reg) = value;
}

uint64_t *computer_sreg(Computer *computer, uint8_t reg)
{

    if (reg >= 32)
    {
        fprintf(stderr, "accessed sreg out of bounds: %d", reg);
        exit(1);
    }
    return computer->reg + reg + 256;
}
uint64_t computer_get_sreg(Computer *computer, uint8_t reg)
{
    return *computer_sreg(computer, reg);
}
void computer_set_sreg(Computer *computer, uint8_t reg, uint64_t value)
{
    *computer_sreg(computer, reg) = value;
}

void computer_destroy(Computer *computer)
{
    free(computer->reg);
    computer->reg = NULL;
    memory_destroy(&computer->memory);
}