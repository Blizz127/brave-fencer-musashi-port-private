/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AEB94 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 a, b, c, d;
} U16x4;
extern U16x4 D_801F8EA0[];
extern u16 D_801F8EA2;
extern u16 D_801F8EA4;
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_80020F34(s32 a0, s32 a1);
extern void func_801AEC38(s32 a0, s32 a1, s32 a2);

void func_801AEB94(void)
{
    register s32 q __asm__("$16"); /* $s0 */
    register s32 i __asm__("$17"); /* $s1 */
    register s32 p __asm__("$18"); /* $s2 */
    s32 loc[8];
    s32 a0v, a1v;

    p = (s32)D_801F8EA0;
    func_80049CAC(p + 0x10, (s32)loc);

    a0v = (s32)loc;
    __asm__ __volatile__("" : "=r"(a0v) : "0"(a0v));
    a1v = p + 8;
    __asm__ __volatile__("" : "=r"(a1v) : "0"(a1v));

    q = p + 0x18;
    loc[5] = *(s16 *)p;
    loc[6] = (s16)D_801F8EA2;
    i = 0;
    loc[7] = (s16)D_801F8EA4;
    func_80020F34(a0v, a1v);

    do {
        if (*(u16 *)q != 0) {
            s32 b0 = p;
            __asm__ __volatile__("" : "=r"(b0) : "0"(b0));
            func_801AEC38(b0, q, (s32)loc);
        }
        i++;
        q += 0x24;
    } while (i < 0x20);
}
