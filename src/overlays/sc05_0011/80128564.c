/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128564 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80011A3C(void);
extern short D_800B9A08;
extern short D_800B99F2;

void func_80128564(void) {
    register s32 p __asm__("$6") = 0x1F8003FC;
    __asm__ __volatile__(
        "addu  $8, %0, $zero\n"
        "sw    $sp, 0($8)\n"
        "addiu $8, $8, -4\n"
        "addu  $sp, $8, $zero\n"
        "jal   func_80178608\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : : "r"(p) : "$8", "memory");
    if (D_800B9A08 == 0x300A) {
        func_8002D4C8(6, 0);
    }
    func_80011A3C();
    D_800B99F2 = 1;
}
