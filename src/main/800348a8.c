/* Exact retail word export for [800348A8,8003491C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_800348A8 - byte-exact against retail at -O2 (tools/register_match.py). */

s32 aF800301A4(void) __asm__("func_800301A4");
extern void func_800301A4(void);
extern s32 func_800348A8(u32);
extern u16 D_800A46E8[];

s32 func_800348A8(u32 arg0) {
    u16 *p;
    u16 *q;
    s32 i;
    u32 lo;
    u32 hi;
    s32 five;

    p = D_800A46E8;
    i = 0;
    five = 5;
    lo = arg0 & 0xFFFF;
    hi = arg0 >> 16;
    q = p + 3;
    do {
        __asm__ ("" :: "r"(i), "r"(i));
        if (p[0] == five && q[-1] == lo) {
            if (hi == 0 || q[0] == hi) {
                return i + 1;
            }
        }
        i++;
        q += 0x2A;
        p += 0x2A;
    } while (i < 8);
    return 0;
}
