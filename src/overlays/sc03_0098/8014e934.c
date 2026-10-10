/* Overlay range [8014E934,8014E98C) from MAIN.CD member 0012: a call on the stack saved in the scratchpad cell. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014E934 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_801C4320;

s32 func_8014E934(s32 a0) {
    s32 lane_outgoing_args[4]; /* the 16-byte outgoing-argument area of the retail frame */
    register s32 p __asm__("$3") = 0x1F8003FC;
    register s32 arg __asm__("$4") = a0;
    __asm__ __volatile__(
        "addu  $8, %0, $zero\n"
        "lw    $9, 0($8)\n"
        "nop\n"
        "sw    $sp, 0($9)\n"
        "addiu $9, $9, -4\n"
        "addu  $sp, $9, $zero\n"
        "jal   func_8014E98C\n"
        "lui   $at, %%hi(D_801C4320)\n"
        "sw    $v0, %%lo(D_801C4320)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : "=r"(p) : "0"(p), "r"(arg) : "$8", "$9", "$31", "memory");
    return D_801C4320;
}
