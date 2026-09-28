/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* GTE mnemonic macros, copied from vendor/bfm-decomp/include/gte_macros.inc (assembler-only, emit no code). */
__asm__(
".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
"    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
".endm\n"
".macro mvmva sf, mx, v, cv, lm\n"
"    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
".endm\n"
);
/* func_800CB9F8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80017DC4(void *a0, void *a1);
extern s32 func_80017758(void *a0, void *a1);

void func_800CB9F8(u16 *a0, u16 *a1, s32 *a2, s32 *a3, s32 stg) {
    struct { s16 v[4]; } p[4];
    s32 w[4];
    s32 hdr[2];
    s16 mat[16];
    void *pa;
    s32 t;

    t = *(volatile s32 *)&stg;
    p[0].v[0] = a0[0] - 8;
    p[0].v[1] = a0[1];
    p[0].v[2] = a0[2];
    p[1].v[0] = a0[0] + 8;
    p[1].v[1] = a0[1];
    p[1].v[2] = a0[2];
    p[2].v[0] = a1[0] - 8;
    p[2].v[1] = a1[1];
    p[2].v[2] = a1[2];
    p[3].v[0] = a1[0] + 8;
    p[3].v[1] = a1[1];
    p[3].v[2] = a1[2];
    w[0] = *(volatile s32 *)a3;
    w[1] = *(volatile s32 *)a3;
    w[2] = *(volatile s32 *)(a3 + 1);
    w[3] = *(volatile s32 *)(a3 + 1);
    hdr[0] = 0x50000000;
    func_80017DC4((void *)t, (void *)mat);
    pa = p;
    __asm__ volatile ( "lw $12, 0( %0 );" "lw $13, 4( %0 );" "ctc2 $12, $0;" "ctc2 $13, $1;" "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );" "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4" : : "r"(  a2  ) : "$12", "$13", "$14", "memory" ) ;
    __asm__ volatile (
        "lhu $12, 0( %0 );"
        "lhu $13, 6( %0 );"
        "lhu $14, 12( %0 );"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0"
        :
        : "r"((s32)mat)
        : "$12", "$13", "$14", "memory");
    __asm__ volatile (
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0( %0 );"
        "sh $13, 6( %0 );"
        "sh $14, 12( %0 )"
        :
        : "r"((s32)mat)
        : "$12", "$13", "$14", "memory");
    __asm__ volatile (
        "lhu $12, 0( %0 );"
        "lhu $13, 6( %0 );"
        "lhu $14, 12( %0 );"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0"
        :
        : "r"((s32)mat + 2)
        : "$12", "$13", "$14", "memory");
    __asm__ volatile (
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0( %0 );"
        "sh $13, 6( %0 );"
        "sh $14, 12( %0 )"
        :
        : "r"((s32)mat + 2)
        : "$12", "$13", "$14", "memory");
    __asm__ volatile (
        "lhu $12, 0( %0 );"
        "lhu $13, 6( %0 );"
        "lhu $14, 12( %0 );"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0"
        :
        : "r"((s32)mat + 4)
        : "$12", "$13", "$14", "memory");
    __asm__ volatile (
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0( %0 );"
        "sh $13, 6( %0 );"
        "sh $14, 12( %0 )"
        :
        : "r"((s32)mat + 4)
        : "$12", "$13", "$14", "memory");
    ((s32 *)mat)[5] = a2[5];
    ((s32 *)mat)[6] = a2[6];
    ((s32 *)mat)[7] = a2[7];
    func_80017758(pa, (void *)mat);
}
