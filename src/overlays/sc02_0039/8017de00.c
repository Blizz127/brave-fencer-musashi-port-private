/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DE00 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern u16 D_8019B538[];

void func_8017DE00(a0p)
s32 a0p;
{
    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register s32 s2 __asm__("$18");
    register s32 v0 __asm__("$2");
    register s32 v1 __asm__("$3");
    register s32 a0 __asm__("$4");
    register s32 a1 __asm__("$5");
    register s32 a2 __asm__("$6");

    s1 = a0p;
    s0 = 0;
    s2 = (s32)D_8019B538;
    __asm__ __volatile__("" : "=r"(s0) : "0"(s0));
    a0 = s0 << 10;
    do {
        v0 = s0 << 1;
        v1 = *(s16 *)(s1 + 0x70);
        s0 = s0 + 1;
        v1 = (v1 << 3) + s2;
        v0 = v0 + v1;
        a1 = *(u16 *)v0;
        a2 = s1;
        a1 = a1 + a0;
        a1 = a1 << 16;
        a0 = 0x199;
        func_8012C658(a0, a1 >> 16, a2);
        a0 = s0 << 10;
    } while (s0 < 4);
    __asm__ __volatile__("" : "=r"(s1) : "0"(s1));
}
