#include "mmix.h"

int main(int argc, char *argv[])
{
    tests_run();
    Computer computer = computer_new();
    Op op = op_decode(0x20000000);
    op_exec(&computer, op);
    computer_destroy(&computer);
    return 0;
}
