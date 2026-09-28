/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* GTE mnemonic macros, copied from vendor/bfm-decomp/include/gte_macros.inc (assembler-only, emit no code). */
__asm__(
".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
"    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
".endm\n"
".macro rtps\n"
"    cop2op 0x01, 0x01\n"
".endm\n"
);
/* func_800CB6F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_800AF648;

s32 func_800CB6F4(int param_1, int param_2)
{
    u8 *r0;
    int iVarX;
    int iVarY;
    int sp[6];
    sp[0] = (int)*(short *)(param_1 + 6);
    sp[1] = (int)*(short *)(param_1 + 10);
    sp[2] = (int)*(short *)(param_1 + 0xe);
    r0 = &D_800AF648;
    __asm__ volatile ( "lw $12, 0( %0 );" "lw $13, 4( %0 );" "ctc2 $12, $0;" "ctc2 $13, $1;" "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );" "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4" : : "r"(  r0  ) : "$12", "$13", "$14" ) ;
    __asm__ volatile ( "lw $12, 20( %0 );" "lw $13, 24( %0 );" "ctc2 $12, $5;" "lw $14, 28( %0 );" "ctc2 $13, $6;" "ctc2 $14, $7" : : "r"(  r0  ) : "$12", "$13", "$14" ) ;
    __asm__ volatile ( "lhu $13, 4( %0 );" "lhu $12, 0( %0 );" "sll $13, $13, 16;" "or $12, $12, $13;" "mtc2 $12, $0;" "lwc2 $1, 8( %0 )" : : "r"(  sp  ) : "$12", "$13" ) ;
    __asm__ volatile ("nop;nop;rtps") ;
    __asm__ volatile ( "swc2 $14, 0( %0 )" : : "r"(  (int *)sp + 4  ) : "memory" ) ;
    iVarX = *(short *)((int)sp + 0x10);
    if (iVarX >= 0) {
        if (iVarX < 0xAB) goto cy;
        goto ret0;
    }
    if (-iVarX >= 0xAB) goto ret0;
cy:
    iVarY = *(short *)((int)sp + 0x12);
    if (iVarY >= 0) {
        if (iVarY < 0x81) goto c1;
        goto ret0;
    }
    if (-iVarY >= 0x81) goto ret0;
c1:
    return 1;
ret0:
    return 0;
}
