/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012EF34 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012EFB8(s32 a0);

void func_8012EF34(s32 a0, s32 a1) {
    s32 sp10;
    register s32 v1 __asm__("$3");
    func_8012EFB8(a0);
    {
        register s32 *p __asm__("$3") = &sp10;
        __asm__ __volatile__("swc2 $19, 0(%0)" : : "r"(p) : "memory");
    }
    v1 = sp10;
    *(s16 *)(a1 + 4) = v1;
}
