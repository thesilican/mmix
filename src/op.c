#include "mmix.h"

// Place holder function for an op code that hasn't been implemented
static void op_not_implemented(Op op) {
    uint32_t code = op_encode(op);
    fprintf(stderr, "op not yet implemented: 0x%08x\n", code);
    exit(1);
}

// Integer arithmetic
// ADD, SUB, MUL, DIV
static void op_int_sarith(Computer *computer, Op op) {
    op_not_implemented(op);
}
// ADDU, SUBU, MULU, DIVU
static void op_int_uarith(Computer *computer, Op op) {
    op_not_implemented(op);
}
// NEG, NEGU
static void op_int_neg(Computer *computer, Op op) {
    op_not_implemented(op);
}
// CMP, CMPU
static void op_int_cmp(Computer *computer, Op op) {
    op_not_implemented(op);
}

// Floating point arithmetic
// FLOT, FLOTU, FIX, FIXU
static void op_float_conv(Computer *computer, Op op) {
    op_not_implemented(op);
}
// FADD, FSUB, FMUL, FDIV, FREM, FSQRT, FINT
static void op_float_arith(Computer *computer, Op op) {
    op_not_implemented(op);
}
// FCMP, FEQL, FUN, FCMPE, FEQLE, FUNE
static void op_float_cmp(Computer *computer, Op op) {
    op_not_implemented(op);
}
// SFLOT, SFLOTU
static void op_float_short(Computer *computer, Op op) {
    op_not_implemented(op);
}

// Bits and Bytes
// AND, OR, XOR, ANDN, ORN, NAND, NOR, NXOR
static void op_bits_logic(Computer *computer, Op op) {
    op_not_implemented(op);
}
// SL, SLU, SR, SRU
static void op_bits_shift(Computer *computer, Op op) {
    op_not_implemented(op);
}
// MOR, MXOR
static void op_bits_mor(Computer *computer, Op op) {
    op_not_implemented(op);
}
// BDIF, WDIF, TDIF, ODIF
static void op_bits_bdif(Computer *computer, Op op) {
    op_not_implemented(op);
}
// ORH, ORMH, ORML, ORL, ANDNH, ANDNMH, ANDNML, ANDNL
static void op_bits_orh(Computer *computer, Op op) {
    op_not_implemented(op);
}
// SADD
static void op_bits_sadd(Computer *computer, Op op) {
    op_not_implemented(op);
}
// MUX
static void op_bits_mux(Computer *computer, Op op) {
    op_not_implemented(op);
}

// Address Computations
// GETA
static void op_addr_geta(Computer *computer, Op op) {
    op_not_implemented(op);
}
// 2ADDU, 4ADDU, 8ADDU, 16ADDU
static void op_addr_2addu(Computer *computer, Op op) {
    op_not_implemented(op);
}
// SETH, SETMH, SETML, SETL
static void op_addr_set(Computer *computer, Op op) {
    op_not_implemented(op);
}
// INCH, INCMH, INCML, INCL
static void op_addr_inc(Computer *computer, Op op) {
    op_not_implemented(op);
}

// Load and Store
// LDB, LDW, LDT, LDO
static void op_ls_ld(Computer *computer, Op op) {
    op_not_implemented(op);
}
// STB, STW, STT, STO
static void op_ls_st(Computer *computer, Op op) {
    op_not_implemented(op);
}
// LDBU, LDWU, LDTU, LDOU
static void op_ls_ldu(Computer *computer, Op op) {
    op_not_implemented(op);
}
// STBU, STWU, STTU, STOU
static void op_ls_stu(Computer *computer, Op op) {
    op_not_implemented(op);
}
// STCO
static void op_ls_stco(Computer *computer, Op op) {
    op_not_implemented(op);
}
// LDHT, STHT
static void op_ls_ht(Computer *computer, Op op) {
    op_not_implemented(op);
}
// LDSF, STSF
static void op_ls_sf(Computer *computer, Op op) {
    op_not_implemented(op);
}

// Jumps and Branches
// JMP
static void op_jb_jmp(Computer *computer, Op op) {
    op_not_implemented(op);
}
// GO
static void op_jb_go(Computer *computer, Op op) {
    op_not_implemented(op);
}
// BZ, PBZ, BNZ, PBNZ, BN, PBN, BNN, PBNN, BP, BPB, BNP, PBNP, BOD, PBOD, BEV,
// PBEV
static void op_jb_branch(Computer *computer, Op op) {
    op_not_implemented(op);
}
// CSZ, ZSZ, CSNZ, ZSNZ, CSN, ZSN, CSNN, ZSNN, CSP, ZSP, CSNP, ZSNP, CSOD, ZSOD,
// CSEV, ZSEV
static void op_jb_cset(Computer *computer, Op op) {
    op_not_implemented(op);
}

// Subroutines and Processes
// PUSHJ, PUSHGO
static void op_subp_push(Computer *computer, Op op) {
    op_not_implemented(op);
}
// POP
static void op_subp_pop(Computer *computer, Op op) {
    op_not_implemented(op);
}
// SAVE, UNSAVE
static void op_subp_save(Computer *computer, Op op) {
    op_not_implemented(op);
}
// CSWAP
static void op_subp_cswap(Computer *computer, Op op) {
    op_not_implemented(op);
}

// Special Registers and System Programming
// PUT, GET
static void op_sreg_put(Computer *computer, Op op) {
    op_not_implemented(op);
}
// TRIP
static void op_sreg_trip(Computer *computer, Op op) {
    op_not_implemented(op);
}
// TRAP
static void op_sreg_trap(Computer *computer, Op op) {
    op_not_implemented(op);
}
// RESUME
static void op_sreg_resume(Computer *computer, Op op) {
    op_not_implemented(op);
}
// LDUNC, STUNC
static void op_sreg_unc(Computer *computer, Op op) {
    op_not_implemented(op);
}
// PRELD, PREST, PREGO
static void op_sreg_pre(Computer *computer, Op op) {
    op_not_implemented(op);
}
// SYNC
static void op_sreg_sync(Computer *computer, Op op) {
    op_not_implemented(op);
}
// SYNCD
static void op_sreg_syncd(Computer *computer, Op op) {
    op_not_implemented(op);
}
// SYNCID
static void op_sreg_syncid(Computer *computer, Op op) {
    op_not_implemented(op);
}
// LDVTS
static void op_sreg_ldvts(Computer *computer, Op op) {
    op_not_implemented(op);
}
// SWYM
static void op_sreg_swym(Computer *computer, Op op) {
    // SWYM is a no-op
}

typedef void OpHandler(Computer *computer, Op op);
static OpHandler *OP_TABLE[256] = {
    op_sreg_trap,   // 0x00 TRAP
    op_float_cmp,   // 0x01 FCMP
    op_float_cmp,   // 0x02 FUN
    op_float_cmp,   // 0x03 FEQL
    op_float_arith, // 0x04 FADD
    op_float_conv,  // 0x05 FIX
    op_float_arith, // 0x06 FSUB
    op_float_conv,  // 0x07 FIXU
    op_float_conv,  // 0x08 FLOT
    op_float_conv,  // 0x09 FLOT[I]
    op_float_conv,  // 0x0a FLOTU
    op_float_conv,  // 0x0b FLOTU[I]
    op_float_short, // 0x0c SFLOT
    op_float_short, // 0x0d SFLOT[I]
    op_float_short, // 0x0e SFLOTU
    op_float_short, // 0x0f SFLOTU[I]
    op_float_arith, // 0x10 FMUL
    op_float_cmp,   // 0x11 FCMPE
    op_float_cmp,   // 0x12 FUNE
    op_float_cmp,   // 0x13 FEQLE
    op_float_arith, // 0x14 FDIV
    op_float_arith, // 0x15 FSQRT
    op_float_arith, // 0x16 FREM
    op_float_arith, // 0x17 FINT
    op_int_sarith,  // 0x18 MUL
    op_int_sarith,  // 0x19 MUL[I]
    op_int_uarith,  // 0x1a MULU
    op_int_uarith,  // 0x1b MULU[I]
    op_int_sarith,  // 0x1c DIV
    op_int_sarith,  // 0x1d DIV[I]
    op_int_uarith,  // 0x1e DIVU
    op_int_uarith,  // 0x1f DIVU[I]
    op_int_sarith,  // 0x20 ADD
    op_int_sarith,  // 0x21 ADD[I]
    op_int_uarith,  // 0x22 ADDU
    op_int_uarith,  // 0x23 ADDU[I]
    op_int_sarith,  // 0x24 SUB
    op_int_sarith,  // 0x25 SUB[I]
    op_int_uarith,  // 0x26 SUBU
    op_int_uarith,  // 0x27 SUBU[I]
    op_addr_2addu,  // 0x28 2ADDU
    op_addr_2addu,  // 0x29 2ADDU[I]
    op_addr_2addu,  // 0x2a 4ADDU
    op_addr_2addu,  // 0x2b 4ADDU[I]
    op_addr_2addu,  // 0x2c 8ADDU
    op_addr_2addu,  // 0x2d 8ADDU[I]
    op_addr_2addu,  // 0x2e 16ADDU
    op_addr_2addu,  // 0x2f 16ADDU[I]
    op_int_cmp,     // 0x30 CMP
    op_int_cmp,     // 0x31 CMP[I]
    op_int_cmp,     // 0x32 CMPU
    op_int_cmp,     // 0x33 CMPU[I]
    op_int_neg,     // 0x34 NEG
    op_int_neg,     // 0x35 NEG[I]
    op_int_neg,     // 0x36 NEGU
    op_int_neg,     // 0x37 NEGU[I]
    op_bits_shift,  // 0x38 SL
    op_bits_shift,  // 0x39 SL[I]
    op_bits_shift,  // 0x3a SLU
    op_bits_shift,  // 0x3b SLU[I]
    op_bits_shift,  // 0x3c SR
    op_bits_shift,  // 0x3d SR[I]
    op_bits_shift,  // 0x3e SRU
    op_bits_shift,  // 0x3f SRU[I]
    op_jb_branch,   // 0x40 BN
    op_jb_branch,   // 0x41 BN[B]
    op_jb_branch,   // 0x42 BZ
    op_jb_branch,   // 0x43 BZ[B]
    op_jb_branch,   // 0x44 BP
    op_jb_branch,   // 0x45 BP[B]
    op_jb_branch,   // 0x46 BOD
    op_jb_branch,   // 0x47 BOD[B]
    op_jb_branch,   // 0x48 BNN
    op_jb_branch,   // 0x49 BNN[B]
    op_jb_branch,   // 0x4a BNZ
    op_jb_branch,   // 0x4b BNZ[B]
    op_jb_branch,   // 0x4c BNP
    op_jb_branch,   // 0x4d BNP[B]
    op_jb_branch,   // 0x4e BEV
    op_jb_branch,   // 0x4f BEV[B]
    op_jb_branch,   // 0x50 PBN
    op_jb_branch,   // 0x51 PBN[B]
    op_jb_branch,   // 0x52 PBZ
    op_jb_branch,   // 0x53 PBZ[B]
    op_jb_branch,   // 0x54 PBP
    op_jb_branch,   // 0x55 PBP[B]
    op_jb_branch,   // 0x56 PBOD
    op_jb_branch,   // 0x57 PBOD[B]
    op_jb_branch,   // 0x58 PBNN
    op_jb_branch,   // 0x59 PBNN[B]
    op_jb_branch,   // 0x5a PBNZ
    op_jb_branch,   // 0x5b PBNZ[B]
    op_jb_branch,   // 0x5c PBNP
    op_jb_branch,   // 0x5d PBNP[B]
    op_jb_branch,   // 0x5e PBEV
    op_jb_branch,   // 0x5f PBEV[B]
    op_jb_cset,     // 0x60 CSN
    op_jb_cset,     // 0x61 CSN[I]
    op_jb_cset,     // 0x62 CSZ
    op_jb_cset,     // 0x63 CSZ[I]
    op_jb_cset,     // 0x64 CSP
    op_jb_cset,     // 0x65 CSP[I]
    op_jb_cset,     // 0x66 CSOD
    op_jb_cset,     // 0x67 CSOD[I]
    op_jb_cset,     // 0x68 CSNN
    op_jb_cset,     // 0x69 CSNN[I]
    op_jb_cset,     // 0x6a CSNZ
    op_jb_cset,     // 0x6b CSNZ[I]
    op_jb_cset,     // 0x6c CSNP
    op_jb_cset,     // 0x6d CSNP[I]
    op_jb_cset,     // 0x6e CSEV
    op_jb_cset,     // 0x6f CSEV[I]
    op_jb_cset,     // 0x70 ZSN
    op_jb_cset,     // 0x71 ZSN[I]
    op_jb_cset,     // 0x72 ZSZ
    op_jb_cset,     // 0x73 ZSZ[I]
    op_jb_cset,     // 0x74 ZSP
    op_jb_cset,     // 0x75 ZSP[I]
    op_jb_cset,     // 0x76 ZSOD
    op_jb_cset,     // 0x77 ZSOD[I]
    op_jb_cset,     // 0x78 ZSNN
    op_jb_cset,     // 0x79 ZSNN[I]
    op_jb_cset,     // 0x7a ZSNZ
    op_jb_cset,     // 0x7b ZSNZ[I]
    op_jb_cset,     // 0x7c ZSNP
    op_jb_cset,     // 0x7d ZSNP[I]
    op_jb_cset,     // 0x7e ZSEV
    op_jb_cset,     // 0x7f ZSEV[I]
    op_ls_ld,       // 0x80 LDB
    op_ls_ld,       // 0x81 LDB[I]
    op_ls_ldu,      // 0x82 LDBU
    op_ls_ldu,      // 0x83 LDBU[I]
    op_ls_ld,       // 0x84 LDW
    op_ls_ld,       // 0x85 LDW[I]
    op_ls_ldu,      // 0x86 LDWU
    op_ls_ldu,      // 0x87 LDWU[I]
    op_ls_ld,       // 0x88 LDT
    op_ls_ld,       // 0x89 LDT[I]
    op_ls_ldu,      // 0x8a LDTU
    op_ls_ldu,      // 0x8b LDTU[I]
    op_ls_ld,       // 0x8c LDO
    op_ls_ld,       // 0x8d LDO[I]
    op_ls_ldu,      // 0x8e LDOU
    op_ls_ldu,      // 0x8f LDOU[I]
    op_ls_sf,       // 0x90 LDSF
    op_ls_sf,       // 0x91 LDSF[I]
    op_ls_ht,       // 0x92 LDHT
    op_ls_ht,       // 0x93 LDHT[I]
    op_subp_cswap,  // 0x94 CSWAP
    op_subp_cswap,  // 0x95 CSWAP[I]
    op_sreg_unc,    // 0x96 LDUNC
    op_sreg_unc,    // 0x97 LDUNC[I]
    op_sreg_ldvts,  // 0x98 LDVTS
    op_sreg_ldvts,  // 0x99 LDVTS[I]
    op_sreg_pre,    // 0x9a PRELD
    op_sreg_pre,    // 0x9b PRELD[I]
    op_sreg_pre,    // 0x9c PREGO
    op_sreg_pre,    // 0x9d PREGO[I]
    op_jb_go,       // 0x9e GO
    op_jb_go,       // 0x9f GO[I]
    op_ls_st,       // 0xa0 STB
    op_ls_st,       // 0xa1 STB[I]
    op_ls_stu,      // 0xa2 STBU
    op_ls_stu,      // 0xa3 STBU[I]
    op_ls_st,       // 0xa4 STW
    op_ls_st,       // 0xa5 STW[I]
    op_ls_stu,      // 0xa6 STWU
    op_ls_stu,      // 0xa7 STWU[I]
    op_ls_st,       // 0xa8 STT
    op_ls_st,       // 0xa9 STT[I]
    op_ls_stu,      // 0xaa STTU
    op_ls_stu,      // 0xab STTU[I]
    op_ls_st,       // 0xac STO
    op_ls_st,       // 0xad STO[I]
    op_ls_stu,      // 0xae STOU
    op_ls_stu,      // 0xaf STOU[I]
    op_ls_st,       // 0xb0 STSF
    op_ls_st,       // 0xb1 STSF[I]
    op_ls_ht,       // 0xb2 STHT
    op_ls_ht,       // 0xb3 STHT[I]
    op_ls_stco,     // 0xb4 STCO
    op_ls_stco,     // 0xb5 STCO[I]
    op_sreg_unc,    // 0xb6 STUNC
    op_sreg_unc,    // 0xb7 STUNC[I]
    op_sreg_syncd,  // 0xb8 SYNCD
    op_sreg_syncd,  // 0xb9 SYNCD[I]
    op_sreg_pre,    // 0xba PREST
    op_sreg_pre,    // 0xbb PREST[I]
    op_sreg_syncid, // 0xbc SYNCID
    op_sreg_syncid, // 0xbd SYNCID[I]
    op_subp_push,   // 0xbe PUSHGO
    op_subp_push,   // 0xbf PUSHGO[I]
    op_bits_logic,  // 0xc0 OR
    op_bits_logic,  // 0xc1 OR[I]
    op_bits_logic,  // 0xc2 ORN
    op_bits_logic,  // 0xc3 ORN[I]
    op_bits_logic,  // 0xc4 NOR
    op_bits_logic,  // 0xc5 NOR[I]
    op_bits_logic,  // 0xc6 XOR
    op_bits_logic,  // 0xc7 XOR[I]
    op_bits_logic,  // 0xc8 AND
    op_bits_logic,  // 0xc9 AND[I]
    op_bits_logic,  // 0xca ANDN
    op_bits_logic,  // 0xcb ANDN[I]
    op_bits_logic,  // 0xcc NAND
    op_bits_logic,  // 0xcd NAND[I]
    op_bits_logic,  // 0xce NXOR
    op_bits_logic,  // 0xcf NXOR[I]
    op_bits_bdif,   // 0xd0 BDIF
    op_bits_bdif,   // 0xd1 BDIF[I]
    op_bits_bdif,   // 0xd2 WDIF
    op_bits_bdif,   // 0xd3 WDIF[I]
    op_bits_bdif,   // 0xd4 TDIF
    op_bits_bdif,   // 0xd5 TDIF[I]
    op_bits_bdif,   // 0xd6 ODIF
    op_bits_bdif,   // 0xd7 ODIF[I]
    op_bits_mux,    // 0xd8 MUX
    op_bits_mux,    // 0xd9 MUX[I]
    op_bits_sadd,   // 0xda SADD
    op_bits_sadd,   // 0xdb SADD[I]
    op_bits_mor,    // 0xdc MOR
    op_bits_mor,    // 0xdd MOR[I]
    op_bits_mor,    // 0xde MXOR
    op_bits_mor,    // 0xdf MXOR[I]
    op_addr_set,    // 0xe0 SETH
    op_addr_set,    // 0xe1 SETMH
    op_addr_set,    // 0xe2 SETML
    op_addr_set,    // 0xe3 SETL
    op_addr_inc,    // 0xe4 INCH
    op_addr_inc,    // 0xe5 INCMH
    op_addr_inc,    // 0xe6 INCML
    op_addr_inc,    // 0xe7 INCL
    op_bits_orh,    // 0xe8 ORH
    op_bits_orh,    // 0xe9 ORMH
    op_bits_orh,    // 0xea ORML
    op_bits_orh,    // 0xeb ORL
    op_bits_orh,    // 0xec ANDNH
    op_bits_orh,    // 0xed ANDNMH
    op_bits_orh,    // 0xee ANDNML
    op_bits_orh,    // 0xef ANDNL
    op_jb_jmp,      // 0xf0 JMP
    op_jb_jmp,      // 0xf1 JMP[B]
    op_subp_push,   // 0xf2 PUSHJ
    op_subp_push,   // 0xf3 PUSHJ[B]
    op_addr_geta,   // 0xf4 GETA
    op_addr_geta,   // 0xf5 GETA[B]
    op_sreg_put,    // 0xf6 PUT
    op_sreg_put,    // 0xf7 PUT[I]
    op_subp_pop,    // 0xf8 POP
    op_sreg_resume, // 0xf9 RESUME
    op_subp_save,   // 0xfa SAVE
    op_subp_save,   // 0xfb UNSAVE
    op_sreg_sync,   // 0xfc SYNC
    op_sreg_swym,   // 0xfd SWYM
    op_sreg_put,    // 0xfe GET
    op_sreg_trip,   // 0xff TRIP
};

Op op_decode(uint32_t tetra) {
    Op op;
    op.op = tetra >> 24;
    op.x = tetra >> 16;
    op.y = tetra >> 8;
    op.z = tetra;
    return op;
}

uint32_t op_encode(Op op) {
    uint32_t value = 0;
    value |= (uint32_t)op.op << 24;
    value |= (uint32_t)op.x << 16;
    value |= (uint32_t)op.y << 8;
    value |= (uint32_t)op.z;
    return value;
}

void op_exec(Computer *computer, Op op) {
    OpHandler *op_handler = OP_TABLE[op.op];
    op_handler(computer, op);
}