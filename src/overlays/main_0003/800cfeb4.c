/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFEB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800599B8(u16 *, u16 *);

s32 func_800CFEB4(u16 *arg0)
{
    register u16 *s2 __asm__("$18");
    register u16 *s0 __asm__("$16");
    u16 sVar1;
    s32 ret;
    s32 flag;
    register s32 i __asm__("$9");
    u16 buf[4];
    s32 pad[2];

    __asm__("" : "=r"(s2) : "0"(arg0));
    sVar1 = *s2;
    ret = 0;
    if (sVar1 != 0xFF) {
        s0 = arg0 + 5;
        do {
            i = 0;
            if (sVar1 == 9) {
                register u16 *p __asm__("$8");
                s32 n;
                s32 base;
                s32 arg2;
                register s32 b __asm__("$7");
                register s32 g __asm__("$4");
                register s32 r __asm__("$6");
                register s32 x __asm__("$2");
                register s32 v __asm__("$2");
                register s32 y __asm__("$4");

                flag = 0;
                n = *(s16 *)(s0 - 1);
                base = *(s32 *)(s0 + 1);
                arg2 = base + n * 2;
                p = (u16 *)arg2;
                if (n > 0) {
                    do {
                        v = *p;
                        b = v & 0x1F;
                        g = v & 0x3E0;
                        r = v & 0x7C00;
                        if (b != 0) b -= 1;
                        if (g != 0) g -= 0x20;
                        x = b | g;
                        if (r != 0) r -= 0x400;
                        y = x | r;
                        if ((y & 0xFFFF) != 0) flag = 1;
                        *p = y;

                        p++;
                    } while (++i < *(s16 *)(s0 - 1));
                }
                if (flag != 0) {
                    buf[0] = s0[-3];
                    buf[1] = s0[-2];
                    buf[2] = s0[-1];
                    buf[3] = s0[0];
                    func_800599B8(buf, (u16 *)arg2);
                }
                ret |= flag;
            }
            s2 += 8;
            sVar1 = *s2;
            s0 += 8;
        } while (sVar1 != 0xFF);
    }
    (void)&pad;
    return ret;
}
