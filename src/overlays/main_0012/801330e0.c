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
/* func_801330E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyTransposeMatrixLV func_8004D504
extern u8 D_800AF648;
extern void ApplyTransposeMatrixLV(void *a0, void *a1, void *a2);

void func_801330E0(param_1, param_2, param_3)
    void *param_1;
    s16 *param_2;
    s16 param_3;
{
    extern u8 D_800AF648;
    s32 *m;
    s32 sxyz[4];
    s32 pos[4];
    s32 flag;
    s32 z;
    m = (s32 *)&D_800AF648;
    __asm__ volatile ( "lw $12, 20( %0 );" "lw $13, 24( %0 );" "ctc2 $12, $5;" "lw $14, 28( %0 );" "ctc2 $13, $6;" "ctc2 $14, $7" : : "r"(  m  ) : "$12", "$13", "$14" ) ;
    __asm__ volatile ( "lw $12, 0( %0 );" "lw $13, 4( %0 );" "ctc2 $12, $0;" "ctc2 $13, $1;" "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );" "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4" : : "r"(  m  ) : "$12", "$13", "$14" ) ;
    __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  param_1  ) ) ;
    __asm__ volatile ( "nop;" "nop;" "mvmva 1, 0, 0, 0, 0" : : : "memory" ) ;
    __asm__ volatile ( "swc2 $25, 0( %0 );" "swc2 $26, 4( %0 );" "swc2 $27, 8( %0 )" : : "r"(  sxyz  ) : "memory" ) ;
    __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &flag  ) : "$12", "memory" ) ;
    z = sxyz[2];
    pos[2] = z + param_3;
    if (z != 0) {
        pos[0] = sxyz[0] * pos[2] / z;
        pos[1] = sxyz[1] * pos[2] / z;
    } else {
        pos[1] = 0;
        pos[0] = 0;
    }
    pos[0] -= m[5];
    pos[1] -= m[6];
    pos[2] -= m[7];
    ApplyTransposeMatrixLV(m, pos, sxyz);
    param_2[0] = sxyz[0];
    param_2[1] = sxyz[1];
    param_2[2] = sxyz[2];
}
