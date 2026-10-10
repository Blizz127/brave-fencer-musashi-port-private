/* Overlay range [801285E4,80128678): MAIN.CD member 0012, two scratchpad stack-switch calls. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801285E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_801D9484;
extern void func_8014607C(void);
extern s32 func_80011A3C(void);

void func_801285E4(void) {
    register s32 p __asm__("$3") = 0x1F8003FC;
    __asm__ __volatile__(
        "addu  $8, %0, $zero\n"
        "sw    $sp, 0($8)\n"
        "addiu $8, $8, -4\n"
        "addu  $sp, $8, $zero\n"
        "jal   func_800D18DC\n"
        "lui   $at, %%hi(D_801D9484)\n"
        "sw    $v0, %%lo(D_801D9484)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : : "r"(p) : "$8", "memory");
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
    if (D_801D9484 != 0) {
        func_80011A3C();
    }
}
