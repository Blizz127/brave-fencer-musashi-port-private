/* SC02.CD member31 [8014F1F4,8014F24C); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014F1F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_801B6400;

/* B28: C plus the scratchpad switch-back asm (a0 passes through to func_8014F24C,
 * its v0 is stored to D_801B6400 and returned); byte-identical (gcc-2.7.2-psx -O2). */
s32 func_8014F1F4(s32 a0) {
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
        "jal   func_8014F24C\n"
        "lui   $at, %%hi(D_801B6400)\n"
        "sw    $v0, %%lo(D_801B6400)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : "=r"(p) : "0"(p), "r"(arg) : "$8", "$9", "$31", "memory");
    return D_801B6400;
}
