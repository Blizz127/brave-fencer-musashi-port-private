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
/* func_8012EFB8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_800AF648;
s32 aF8012EFB8(void *param_1, void *param_2) __asm__("func_8012EFB8");
s32 aF8012EFB8() __asm__("func_8012EFB8");

s32 aF8012EFB8(param_1, param_2)
    void *param_1;
    void *param_2;
{
    extern u8 D_800AF648;
    s32 *m;
    s32 flag;
    m = (s32 *)&D_800AF648;
    __asm__ volatile ( "lw $12, 0( %0 );" "lw $13, 4( %0 );" "ctc2 $12, $0;" "ctc2 $13, $1;" "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );" "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4" : : "r"(  m  ) : "$12", "$13", "$14" ) ;
    __asm__ volatile ( "lw $12, 20( %0 );" "lw $13, 24( %0 );" "ctc2 $12, $5;" "lw $14, 28( %0 );" "ctc2 $13, $6;" "ctc2 $14, $7" : : "r"(  m  ) : "$12", "$13", "$14" ) ;
    __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  param_1  ) ) ;
    __asm__ volatile ("nop;nop;rtps") ;
    __asm__ volatile ( "swc2 $14, 0( %0 )" : : "r"(  param_2  ) : "memory" ) ;
    __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &flag  ) : "$12", "memory" ) ;
    return flag;
}
