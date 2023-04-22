#include "mmix.h"

Op op_new(uint32_t tetra)
{
    Op op;
    op.op = tetra >> 24;
    op.x = tetra >> 16;
    op.y = tetra >> 8;
    op.z = tetra;
    return op;
}

void op_apply(Computer *computer, Op op)
{
    // TODO
}

// Integer arithmetic
// ADD, SUB, MUL, DIV
void op_int_sarith(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// ADDU, SUBU, MULU, DIVU
void op_int_uarith(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// NEG, NEGU
void op_int_neg(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// CMP, CMPU
void op_int_cmp(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}

// Floating point arithmetic
// FLOT, FLOTU, FIX, FIXU
void op_float_conv(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// FADD, FSUB, FMUL, FDIV, FREM, FSQRT, FINT
void op_float_arith(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// FCMP, FEQL, FUN, FCMPE, FEQLE, FUNE
void op_float_cmp(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// SFLOT, SFLOTU
void op_float_short(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}

// Bits and Bytes
// AND, OR, XOR, ANDN, ORN, NAND, NOR, NXOR
void op_bits_logic(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// SL, SLU, SR, SRU
void op_bits_shift(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// MOR, MXOR
void op_bits_mor(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// BDIF, WDIF, TDIF, ODIF
void op_bits_bdif(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// ORH, ORMH, ORML, ORL, ANDNH, ANDNMH, ANDNML, ANDNL
void op_bits_orh(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// SADD
void op_bits_sadd(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// MUX
void op_bits_mux(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}

// Address Computations
// LDA
void op_addr_lda(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// GETA
void op_addr_geta(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// 2ADDU, 4ADDU, 8ADDU, 16ADDU
void op_addr_2addu(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// SETH, SETMH, SETML, SETL
void op_addr_set(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// INCH, INCMH, INCML, INCL
void op_addr_inc(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}

// Load and Store
// LDB, LDW, LDT, LDO
void op_ls_ld(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// STB, STW, STT, STO
void op_ls_st(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// STCO
void op_ls_stco(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// LDBU, LDWU, LDTU, LDOU
void op_ls_ldu(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// STBU, STWU, STTU, STOU
void op_ls_stu(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// STHT
void op_ls_stht(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// LDSF, STSF
void op_ls_ldsf(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}

// Jumps and Branches
// JMP
void op_jb_jmp(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// GO
void op_jb_go(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// BZ, PBZ, BNZ, PBNZ, BN, PBN, BNN, PBNN, BP, BPB, BNP, PBNP, BOD, PBOD, BEV, PBEV
void op_jb_branch(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// CSZ, ZSZ, CSNZ, ZSNZ, CSN, ZSN, CSNN, ZSNN, CSP, ZSP, CSNP, ZSNP, CSOD, ZSOD, CSEV, ZSEV
void op_jb_cset(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}

// Subroutines and Processes
// PUSHJ, PUSHGO
void op_subp_push(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// POP
void op_subp_pop(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// SAVE, UNSAVE
void op_subp_save(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// CSWAP
void op_subp_cswap(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}

// Special Registers and System Programming
// PUT, GET
void op_sreg_put(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// TRIP
void op_sreg_trip(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// TRAP
void op_sreg_trap(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// RESUME
void op_sreg_resume(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// LDUNC, STUNC
void op_sreg_unc(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// PRELD, PREST, PREGO
void op_sreg_pre(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// SYNC
void op_sreg_sync(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// SYNCID
void op_sreg_syncid(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// SYNCCD
void op_sreg_synccd(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// LDVTS
void op_sreg_ldvts(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}
// SWYM
void op_sreg_swym(Computer *computer, Op op)
{
    fprintf(stderr, "op not yet implemented: 0x%x", op.op);
    exit(1);
}