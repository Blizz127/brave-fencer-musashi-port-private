/* Overlay range [8014E434,8014E48C) from MAIN.CD member 0012.
 * SHA256(span)=8b0ae38dd3a488d02e5ec8a280d4b93162c8bcbfbc7a600e4f1f7f63204d4c09.
 * Word export for the native seam. */
#include "psx_types.h"

extern s32 D_80184248;

/* B28: C plus the scratchpad switch-back asm (a0 passes through to func_8014E48C,
 * its v0 is stored to D_80184248 and returned); byte-identical (gcc-2.7.2-psx -O2). */
s32 func_8014E434(s32 a0) {
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
        "jal   func_8014E48C\n"
        "lui   $at, %%hi(D_80184248)\n"
        "sw    $v0, %%lo(D_80184248)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : "=r"(p) : "0"(p), "r"(arg) : "$8", "$9", "$31", "memory");
    return D_80184248;
}
