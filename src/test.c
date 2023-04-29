#include "mmix.h"

// Test direct memory access function
static void test_memory() {
    Memory mem = memory_new();
    *memory_get(&mem, 0x00) = 0xab;
    *memory_get(&mem, 0x01) = 0xcd;
    *memory_get(&mem, 0x02) = 0xef;
    *memory_get(&mem, 0x0123) = 0xfe;
    *memory_get(&mem, 0x4567) = 0xed;
    *memory_get(&mem, 0x89ab) = 0xca;
    *memory_get(&mem, 0xcdef) = 0x01;
    *memory_get(&mem, 0xabcdabcdabcdabcd) = 0xff;
    *memory_get(&mem, 0xefefefefefefefef) = 0xff;
    assert(*memory_get(&mem, 0x00) == 0xab);
    assert(*memory_get(&mem, 0x01) == 0xcd);
    assert(*memory_get(&mem, 0x02) == 0xef);
    assert(*memory_get(&mem, 0x0123) == 0xfe);
    assert(*memory_get(&mem, 0x4567) == 0xed);
    assert(*memory_get(&mem, 0x89ab) == 0xca);
    assert(*memory_get(&mem, 0xcdef) == 0x01);
    assert(*memory_get(&mem, 0xabcdabcdabcdabcd) == 0xff);
    assert(*memory_get(&mem, 0xefefefefefefefef) == 0xff);
    memory_destroy(&mem);
}

// Test memory byte/wyde/tetra/octa access functions
static void test_memory_fetch() {
    Memory mem = memory_new();
    memory_set_octa(&mem, 1000, 0x0123456789abcdef);
    assert(*memory_get(&mem, 1000) == 0x01);
    assert(*memory_get(&mem, 1001) == 0x23);
    assert(*memory_get(&mem, 1002) == 0x45);
    assert(*memory_get(&mem, 1003) == 0x67);
    assert(*memory_get(&mem, 1004) == 0x89);
    assert(*memory_get(&mem, 1005) == 0xab);
    assert(*memory_get(&mem, 1006) == 0xcd);
    assert(*memory_get(&mem, 1007) == 0xef);
    assert(memory_get_byte(&mem, 1002) == 0x45);
    assert(memory_get_wyde(&mem, 1002) == 0x4567);
    assert(memory_get_tetra(&mem, 1002) == 0x01234567);
    assert(memory_get_octa(&mem, 1002) == 0x0123456789abcdef);
    assert(memory_get_byte(&mem, 1005) == 0xab);
    assert(memory_get_wyde(&mem, 1005) == 0x89ab);
    assert(memory_get_tetra(&mem, 1005) == 0x89abcdef);
    assert(memory_get_octa(&mem, 1005) == 0x0123456789abcdef);
    memory_set_byte(&mem, 1002, 0xde);
    assert(memory_get_octa(&mem, 1002) == 0x0123de6789abcdef);
    memory_set_wyde(&mem, 1002, 0xdead);
    assert(memory_get_octa(&mem, 1002) == 0x0123dead89abcdef);
    memory_set_tetra(&mem, 1002, 0xdeadfeed);
    assert(memory_get_octa(&mem, 1002) == 0xdeadfeed89abcdef);
    memory_set_octa(&mem, 1002, 0xdeadfeed00001234);
    assert(memory_get_octa(&mem, 1002) == 0xdeadfeed00001234);
    memory_destroy(&mem);
}

// Test computer registers
static void test_computer_reg() {
    Computer computer = computer_new();
    *computer_greg(&computer, 0x00) = 0x0123456789abcdef;
    *computer_greg(&computer, 0x12) = 0xeeee;
    *computer_greg(&computer, 0xff) = 1234;
    assert(computer_get_greg(&computer, 0x00) == 0x0123456789abcdef);
    assert(computer_get_greg(&computer, 0x12) == 0xeeee);
    assert(computer_get_greg(&computer, 0xff) == 1234);
    computer_set_greg(&computer, 0x00, 1);
    computer_set_greg(&computer, 0x12, 2);
    computer_set_greg(&computer, 0xff, 3);
    assert(computer_get_greg(&computer, 0x00) == 1);
    assert(computer_get_greg(&computer, 0x12) == 2);
    assert(computer_get_greg(&computer, 0xff) == 3);
    *computer_sreg(&computer, 0) = 0x0123456789abcdef;
    *computer_sreg(&computer, 1) = 0xeeee;
    *computer_sreg(&computer, 31) = 1234;
    assert(computer_get_sreg(&computer, 0) == 0x0123456789abcdef);
    assert(computer_get_sreg(&computer, 1) == 0xeeee);
    assert(computer_get_sreg(&computer, 31) == 1234);
    computer_set_sreg(&computer, 0, 1);
    computer_set_sreg(&computer, 1, 2);
    computer_set_sreg(&computer, 31, 3);
    assert(computer_get_sreg(&computer, 0) == 1);
    assert(computer_get_sreg(&computer, 1) == 2);
    assert(computer_get_sreg(&computer, 31) == 3);
    computer_destroy(&computer);
}

void tests_run() {
    clock_t start = clock();
    test_memory();
    test_memory_fetch();
    test_computer_reg();
    test_ops();
    clock_t end = clock();
    double ms = (double)(end - start) * 1000 / (double)CLOCKS_PER_SEC;
    printf("Completed all tests in %.2fms\n", ms);
}
