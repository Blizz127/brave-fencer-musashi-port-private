/* SC02.CD member31 [80128678,...); the C body is the canonical
 * scratch-call form (as main_0012 80128678, differing only in globals),
 * re-verified byte-identical against retail. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80128678 - 39 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80029444(void);
extern void func_8014607C(void);
extern void func_801287B8(void);
extern void func_800D1754(void);

void func_80128678(void) {
    register s32 p __asm__("$2") = 0x1F8003FC;
    __asm__ __volatile__(
        "addu  $8, %0, $zero\n"
        "sw    $sp, 0($8)\n"
        "addiu $8, $8, -4\n"
        "addu  $sp, $8, $zero\n"
        "jal   func_80029444\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : : "r"(p) : "$8", "memory");
    func_8014607C();
    {
        register s32 q __asm__("$2") = 0x1F8003FC;
        __asm__ __volatile__(
            "addu  $8, %0, $zero\n"
            "sw    $sp, 0($8)\n"
            "addiu $8, $8, -4\n"
            "addu  $sp, $8, $zero\n"
            "jal   func_801287B8\n"
            "addiu $sp, $sp, 4\n"
            "lw    $sp, 0($sp)\n"
            : "=r"(q) : "0"(q) : "$8", "memory");
    }
    {
        register s32 r __asm__("$2") = 0x1F8003FC;
        __asm__ __volatile__(
            "addu  $8, %0, $zero\n"
            "sw    $sp, 0($8)\n"
            "addiu $8, $8, -4\n"
            "addu  $sp, $8, $zero\n"
            "jal   func_800D1754\n"
            "addiu $sp, $sp, 4\n"
            "lw    $sp, 0($sp)\n"
            : : "r"(r) : "$8", "memory");
    }
}
