/* Overlay range [8014FBC0,8014FC18) from MAIN.CD member 0012.
 * SHA256(span)=50a22ddd30f7dda917052025fa18e08b7a7ac7fee5e112fe3102b3533dfdf6de.
 * Word export for the native seam. */
#include "psx_types.h"

extern void func_8014FC18(void);

void func_8014FBC0(void)
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
        "jal   func_8014FC18\n"
        "lui   $at, %%hi(D_8018424C)\n"
        "sw    $v0, %%lo(D_8018424C)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        "lui   $v0, %%hi(D_8018424C)\n"
        "lw    $v0, %%lo(D_8018424C)($v0)\n"
        "lw    $ra, 16($sp)\n"
        "addiu $sp, $sp, 24\n"
        : : : "memory");
}

