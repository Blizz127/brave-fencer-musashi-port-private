/* Overlay range [80128714,801287B8) from MAIN.CD member 0012.
 * SHA256(span)=533c1c80c06be0552333ab4422f28c8189a560c734aea1c05bd581da579de2d2.
 * Word export for the native seam; the C body is the canonical
 * scratch-call form, re-verified byte-identical against retail at -O2. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

extern s32 D_801D9484;
extern void func_8014607C(void);
extern void func_8001903C(void);
extern void func_80018FC8(void);
/* func_80128714 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80128714(void) {
    register s32 p __asm__("$3") = 0x1F8003FC;
    __asm__ __volatile__(
        "addu  $8, %0, $zero\n"
        "sw    $sp, 0($8)\n"
        "addiu $8, $8, -4\n"
        "addu  $sp, $8, $zero\n"
        "jal   func_800D19F0\n"
        "lui   $at, %%hi(D_801D9484)\n"
        "sw    $v0, %%lo(D_801D9484)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : : "r"(p) : "$8", "memory");
    if (D_801D9484 == 0) {
        func_8014607C();
        {
            register s32 q __asm__("$3") = 0x1F8003FC;
            __asm__ __volatile__(
                "addu  $8, %0, $zero\n"
                "sw    $sp, 0($8)\n"
                "addiu $8, $8, -4\n"
                "addu  $sp, $8, $zero\n"
                "jal   func_801287B8\n"
                "addiu $sp, $sp, 4\n"
                "lw    $sp, 0($sp)\n"
                : : "r"(q) : "$8", "memory");
        }
    } else {
        func_8001903C();
        func_80018FC8();
    }
}
