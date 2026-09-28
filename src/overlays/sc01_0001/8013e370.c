/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E370 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void *D_801274CC;
extern s32 func_8013E410(void);
extern s32 func_8013E448(s32 a0);
extern void func_8012C724(s32 a0, s32 a1);

void func_8013E370(void) {
    u8 *s0;
    u8 *s2;
    s32 r;
    s0 = (u8 *)D_801274CC;
    if (s0 == 0) return;
    if (*(u16 *)(s0 + 6) == 0) return;
    s2 = s0 + 6;
    do {
        if ((*(u16 *)(s2 + 4) & 0x8000) == 0) {
            r = func_8013E410();
            if (r == 0) return;
            if (func_8013E448((s32)s0) != 0) {
                func_8012C724((s32)s0, r);
            }
        }
        s2 += 0x14;
        s0 += 0x14;
    } while (*(u16 *)s2 != 0);
}
