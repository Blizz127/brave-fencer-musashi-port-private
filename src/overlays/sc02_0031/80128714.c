/* SC02.CD member31 [80128714,...); the C body is the canonical
 * scratch-call form (as main_0012 80128714, differing only in globals),
 * re-verified byte-identical against retail. */
#include "psx_types.h"

extern s32 D_801B626C;
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
        "lui   $at, %%hi(D_801B626C)\n"
        "sw    $v0, %%lo(D_801B626C)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : : "r"(p) : "$8", "memory");
    if (D_801B626C == 0) {
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
