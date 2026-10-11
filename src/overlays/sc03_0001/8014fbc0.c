/* Overlay range [8014FBC0,8014FC18) from MAIN.CD member 0012.
 * SHA256(span)=50a22ddd30f7dda917052025fa18e08b7a7ac7fee5e112fe3102b3533dfdf6de.
 * Word export for the native seam. */
#include "psx_types.h"

extern s32 D_801ED4DC;

/* B28: C plus the scratchpad switch-back asm (a0 passes through to func_8014FC18,
 * its v0 is stored to D_801ED4DC and returned); byte-identical (gcc-2.7.2-psx -O2). */
s32 func_8014FBC0(s32 a0) {
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
        "jal   func_8014FC18\n"
        "lui   $at, %%hi(D_801ED4DC)\n"
        "sw    $v0, %%lo(D_801ED4DC)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : "=r"(p) : "0"(p), "r"(arg) : "$8", "$9", "$31", "memory");
    return D_801ED4DC;
}
