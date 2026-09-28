/* Main-exec range [80015018,80015118) from the SLUS executable.
 * SHA256(span)=703077d2fcf8c726b143074b588c1a481ae87a9d0f2f7b3a2c41169020c3e2f3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80015018 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078D98;
extern void func_80015118(u16 *arg);

s32 func_80015018(s32 a0) {
    u8 *p;
    u8 *q;
    u16 val;
    u16 tmp[2];
    s32 result;

    p = (u8 *)&D_80078D98 + (a0 & 0xFF) * 76;
    val = *(u16 *)(p + 0x32);
    if (val != 0) {
        return val;
    }

    {
        s32 c = *p;
        if (c != 0x53) {
            if (c < 0x54) {
                return 0;
            }
            if (c != 0x73) {
                return 0;
            }
        }
    }

    q = (u8 *)&D_80078D98 + (a0 & 0xFF) * 76;
    tmp[0] = *(q + 0x37);
    tmp[1] = *(q + 0x36);
    func_80015118(&tmp[0]);
    func_80015118(&tmp[1]);

    result = 0;
    if (tmp[0] != 0x80) {
        if (tmp[0] >= 0x80) {
            result = 0x4000;
        } else {
            result = 0x1000;
        }
    }

    if (tmp[1] != 0x80) {
        if (tmp[1] < 0x80) {
            result |= 0x8000;
        } else {
            result |= 0x2000;
        }
    }

    return result & 0xFFFF;
}
