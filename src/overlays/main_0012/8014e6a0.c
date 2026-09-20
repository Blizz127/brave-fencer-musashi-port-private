/* Overlay range [8014E6A0,8014E6F8) from MAIN.CD member 0012.
 * SHA256(span)=96c873df6b7e1a74a580d48ef92d7dfbcc557a96d21771ef01019ef27cdeccfb.
 * Word export for the native seam. */
#include "psx_types.h"

extern void func_8014E6F8(void);

void func_8014E6A0(void)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "addiu $sp, $sp, -24\n"
        "lui   $v1, 0x1f80\n"
        "ori   $v1, $v1, 0x03fc\n"
        "sw    $ra, 16($sp)\n"
        "addu  $t0, $v1, $zero\n"
        "lw    $t1, 0($t0)\n"
        "nop\n"
        "sw    $sp, 0($t1)\n"
        "addiu $t1, $t1, -4\n"
        "addu  $sp, $t1, $zero\n"
        "jal   func_8014E6F8\n"
        "lui   $at, %%hi(D_80184248)\n"
        "sw    $v0, %%lo(D_80184248)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        "lui   $v0, %%hi(D_80184248)\n"
        "lw    $v0, %%lo(D_80184248)($v0)\n"
        "lw    $ra, 16($sp)\n"
        "addiu $sp, $sp, 24\n"
        : : : "memory");
}

