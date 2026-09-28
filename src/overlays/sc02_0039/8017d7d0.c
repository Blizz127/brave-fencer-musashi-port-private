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
/* func_8017D7D0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8017D7D0(s32 param_1, s32 *param_2)
{
    s32 s0;
    s32 s1;
    s32 cos_val;
    s16 sin_val;
    s32 v1;
    s16 matrix_stack[16];

    s1 = (s32)param_2;
    s0 = param_1 & 0xFFF;

    cos_val = func_8017DBD0(s0);
    sin_val = func_8017DB14(s0);

     
    v1 = 0x7FF8;
    *(short *)((s32)matrix_stack + 0x04) = sin_val;
    *(short *)((s32)matrix_stack + 0x00) = cos_val;
    *(short *)((s32)matrix_stack + 0x02) = 0;
    *(short *)((s32)matrix_stack + 0x06) = 0;
    *(short *)((s32)matrix_stack + 0x08) = v1;
    *(short *)((s32)matrix_stack + 0x0A) = 0;
    *(short *)((s32)matrix_stack + 0x0C) = -sin_val;
    *(short *)((s32)matrix_stack + 0x0E) = 0;
    *(short *)((s32)matrix_stack + 0x10) = cos_val;

    __asm__ volatile (
        "lw $12, 0(%0);"
        "lw $13, 4(%0);"
        "ctc2 $12, $0;"
        "ctc2 $13, $1;"
        "lw $12, 8(%0);"
        "lw $13, 12(%0);"
        "lw $14, 16(%0);"
        "ctc2 $12, $2;"
        "ctc2 $13, $3;"
        "ctc2 $14, $4;"
        "addiu $2, $sp, 0x10;"
        "lhu $12, 0($2);"
        "lhu $13, 6($2);"
        "lhu $14, 12($2);"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0;"
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0(%0);"
        "sh $13, 6(%0);"
        "sh $14, 12(%0);"
        "addiu $2, $sp, 0x12;"
        "lhu $12, 0($2);"
        "lhu $13, 6($2);"
        "lhu $14, 12($2);"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0;"
        "addiu $2, %0, 0x2;"
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0($2);"
        "sh $13, 6($2);"
        "sh $14, 12($2);"
        "addiu $2, $sp, 0x14;"
        "lhu $12, 0($2);"
        "lhu $13, 6($2);"
        "lhu $14, 12($2);"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0;"
        "addiu %0, %0, 4;"
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0(%0);"
        "sh $13, 6(%0);"
        "sh $14, 12(%0)"
        : "=r"(s1)
        : "0"(s1)
        : "$12", "$13", "$14", "$2"
    );
}
