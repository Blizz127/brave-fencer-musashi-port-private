/* SC02.CD member35 [8014D3E0,8014D438): twin of main_0012 8014D3E0 (src/overlays/main_0012/8014d3e0.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [8014D3E0,8014D438) from MAIN.CD member 0012.
 * SHA256(span)=574825d2ff58f824e635a11c062eda1425dbae5b7d1575191c267c1e18e6cf5d.
 * Word export for the native seam. */
#include "psx_types.h"

extern s32 D_801BD730;

/* B28: C plus the scratchpad switch-back asm (a0 passes through to func_8014D438,
 * its v0 is stored to D_801BD730 and returned); byte-identical (gcc-2.7.2-psx -O2). */
s32 func_8014D3E0(s32 a0) {
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
        "jal   func_8014D438\n"
        "lui   $at, %%hi(D_801BD730)\n"
        "sw    $v0, %%lo(D_801BD730)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : "=r"(p) : "0"(p), "r"(arg) : "$8", "$9", "$31", "memory");
    return D_801BD730;
}
