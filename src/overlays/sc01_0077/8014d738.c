/* Overlay range [8014D738,8014D790) from MAIN.CD member 0012.
 * SHA256(span)=ecc573253420085bd4e1f98311596fcf1576d77d91d0557ed64dab359a883b87.
 * Word export for the native seam. */
#include "psx_types.h"

extern s32 D_801D9618;

/* B28: C plus the scratchpad switch-back asm (a0 passes through to func_8014D790,
 * its v0 is stored to D_801D9618 and returned); byte-identical (gcc-2.7.2-psx -O2). */
s32 func_8014D738(s32 a0) {
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
        "jal   func_8014D790\n"
        "lui   $at, %%hi(D_801D9618)\n"
        "sw    $v0, %%lo(D_801D9618)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : "=r"(p) : "0"(p), "r"(arg) : "$8", "$9", "$31", "memory");
    return D_801D9618;
}
