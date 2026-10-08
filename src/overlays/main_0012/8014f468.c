/* Overlay range [8014F468,8014F4C0) from MAIN.CD member 0012.
 * SHA256(span)=42bbc18959d1281a42df172a3d4ef74f66f79652e7518a9f44280dc577720fe3.
 * Word export for the native seam. */
#include "psx_types.h"

extern s32 D_8018424C;

/* B28: C plus the scratchpad switch-back asm (a0 passes through to func_8014F4C0,
 * its v0 is stored to D_8018424C and returned); byte-identical (gcc-2.7.2-psx -O2). */
s32 func_8014F468(s32 a0) {
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
        "jal   func_8014F4C0\n"
        "lui   $at, %%hi(D_8018424C)\n"
        "sw    $v0, %%lo(D_8018424C)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : "=r"(p) : "0"(p), "r"(arg) : "$8", "$9", "$31", "memory");
    return D_8018424C;
}
