#ifndef MMIX_H
#define MMIX_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct Computer Computer;
typedef struct Memory Memory;
typedef struct MemoryPageNode MemoryPageNode;
typedef struct Op Op;

#define MEMORY_PAGE_MAX_NODES 65536

struct MemoryPageNode
{
    // For leaf node, children[1] contains page index,
    // children[0] is set to 1 if page is allocated otherwise 0
    // For other nodes, children[i] contains index of next node
    // or 0 if there is no next node (conveniently index 0 is the root node,
    // which is never referenced)
    size_t children[256];
};

// There is 2^64 bytes of addressable memory
// Memory is stored in pages that are 2^16 bytes each, a tree of
// nodes maps the remaining 2^48 address space to its corresponding page. Each node
// narrows the search space by a factor of 2^8
struct Memory
{
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

struct Computer
{
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

struct Op
{
    uint8_t op;
    uint8_t x;
    uint8_t y;
    uint8_t z;
};

// Apply op to a computer state
void op_apply(Computer *computer, Op op);

// Integer arithmetic
// ADD, SUB, MUL, DIV
void op_int_sarith(Computer *computer, Op op);
// ADDU, SUBU, MULU, DIVU
void op_int_uarith(Computer *computer, Op op);
// NEG, NEGU
void op_int_neg(Computer *computer, Op op);
// CMP, CMPU
void op_int_cmp(Computer *computer, Op op);

// Floating point arithmetic
// FLOT, FLOTU, FIX, FIXU
void op_float_conv(Computer *computer, Op op);
// FADD, FSUB, FMUL, FDIV, FREM, FSQRT, FINT
void op_float_arith(Computer *computer, Op op);
// FCMP, FEQL, FUN, FCMPE, FEQLE, FUNE
void op_float_cmp(Computer *computer, Op op);
// SFLOT, SFLOTU
void op_float_short(Computer *computer, Op op);

// Bits and Bytes
// AND, OR, XOR, ANDN, ORN, NAND, NOR, NXOR
void op_bits_logic(Computer *computer, Op op);
// SL, SLU, SR, SRU
void op_bits_shift(Computer *computer, Op op);
// MOR, MXOR
void op_bits_mor(Computer *computer, Op op);
// BDIF, WDIF, TDIF, ODIF
void op_bits_bdif(Computer *computer, Op op);
// ORH, ORMH, ORML, ORL, ANDNH, ANDNMH, ANDNML, ANDNL
void op_bits_orh(Computer *computer, Op op);
// SADD
void op_bits_sadd(Computer *computer, Op op);
// MUX
void op_bits_mux(Computer *computer, Op op);

// Address Computations
// LDA
void op_addr_lda(Computer *computer, Op op);
// GETA
void op_addr_geta(Computer *computer, Op op);
// 2ADDU, 4ADDU, 8ADDU, 16ADDU
void op_addr_2addu(Computer *computer, Op op);
// SETH, SETMH, SETML, SETL
void op_addr_set(Computer *computer, Op op);
// INCH, INCMH, INCML, INCL
void op_addr_inc(Computer *computer, Op op);

// Load and Store
// LDB, LDW, LDT, LDO
void op_ls_ld(Computer *computer, Op op);
// STB, STW, STT, STO
void op_ls_st(Computer *computer, Op op);
// STCO
void op_ls_stco(Computer *computer, Op op);
// LDBU, LDWU, LDTU, LDOU
void op_ls_ldu(Computer *computer, Op op);
// STBU, STWU, STTU, STOU
void op_ls_stu(Computer *computer, Op op);
// STHT
void op_ls_stht(Computer *computer, Op op);
// LDSF, STSF
void op_ls_ldsf(Computer *computer, Op op);

// Jumps and Branches
// JMP
void op_jb_jmp(Computer *computer, Op op);
// GO
void op_jb_go(Computer *computer, Op op);
// BZ, PBZ, BNZ, PBNZ, BN, PBN, BNN, PBNN, BP, BPB, BNP, PBNP, BOD, PBOD, BEV, PBEV
void op_jb_branch(Computer *computer, Op op);
// CSZ, ZSZ, CSNZ, ZSNZ, CSN, ZSN, CSNN, ZSNN, CSP, ZSP, CSNP, ZSNP, CSOD, ZSOD, CSEV, ZSEV
void op_jb_cset(Computer *computer, Op op);

// Subroutines and Processes
// PUSHJ, PUSHGO
void op_subp_push(Computer *computer, Op op);
// POP
void op_subp_pop(Computer *computer, Op op);
// SAVE, UNSAVE
void op_subp_save(Computer *computer, Op op);
// CSWAP
void op_subp_cswap(Computer *computer, Op op);

// Special Registers and System Programming
// PUT, GET
void op_sreg_put(Computer *computer, Op op);
// TRIP
void op_sreg_trip(Computer *computer, Op op);
// TRAP
void op_sreg_trap(Computer *computer, Op op);
// RESUME
void op_sreg_resume(Computer *computer, Op op);
// LDUNC, STUNC
void op_sreg_unc(Computer *computer, Op op);
// PRELD, PREST, PREGO
void op_sreg_pre(Computer *computer, Op op);
// SYNC
void op_sreg_sync(Computer *computer, Op op);
// SYNCID
void op_sreg_syncid(Computer *computer, Op op);
// SYNCCD
void op_sreg_synccd(Computer *computer, Op op);
// LDVTS
void op_sreg_ldvts(Computer *computer, Op op);
// SWYM
void op_sreg_swym(Computer *computer, Op op);

#endif