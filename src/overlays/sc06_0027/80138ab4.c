/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80138AB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_80127540[4];
extern s32 func_80139D04(s32 a0, s32 a1);
extern s32 func_80138DE0(u8 *arg0, u8 arg1, s32 arg2);
extern void func_80139B18(s32 a0);

void func_80138AB4(s32 a0) {
    u8 sp10[8];
    s32 s0 = a0;
    s32 s1;
    s32 a0v;
    s1 = func_80139D04((s32)sp10, (u16)D_80127540[*(u16 *)(s0 + 0x48)]) & 0xFFFF;
    do {
        s32 v1 = *(u16 *)(s0 + 0x44);
        a0v = 0;
        if ((s32)v1 < s1) {
            s32 a1v = (sp10[v1] + 0x30) & 0xFF;
            a0v = func_80138DE0(s0, a1v, 0);
            if (*(s32 *)(s0 + 0x8) & 0x80220) {
                /* a0v stays */
            } else {
                a0v = 0;
            }
        } else {
            s32 t = *(u16 *)(s0 + 0x48);
            if ((u32)t < 3) {
                *(s16 *)(s0 + 0x48) = t + 1;
            }
            *(s16 *)(s0 + 0x4) = 2;
        }
    } while (a0v != 0);
    func_80139B18(s0);
}
