/* Main-exec range [8002F80C,8002FA3C) from the SLUS executable.
 * SHA256(span)=9983ee8799f00e2261bc9d9a2d1bd97eb085452dfcb410f09a5df05db716bfe4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002F80C - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_8006A96E;
extern s16 D_8006A96C;
extern u8 D_800760D0;
extern u8 D_800760D4;
extern u8 D_800760D8;
extern u8 D_800760DC;
extern s8 D_800A4F17;
extern u8 D_800A4F18;
extern s16 D_800A4EFC;
extern void (*D_800A4F24)(void);

extern s32 func_8002DC68();
extern void func_8002E138(s32 a0, s32 a1, s32 a2);
extern void func_80030F80(void);
extern void func_8002D320(void);
extern void func_80031BE0(void);

void func_8002F80C(void) {
    u8 flag;
    s16 max;
    u8 a0;
    u8 v0;

    flag = 0;
    max = 0;
    if ((D_8006A96E & 1) != 0) {
        flag = 1;
        max = D_800760D0;
    }
    if ((D_8006A96E & 2) != 0) {
        flag = 1;
        if (max < D_800760D4) {
            max = D_800760D4;
        }
    }
    if ((D_8006A96E & 4) != 0) {
        flag = 1;
        if (max < D_800760D8) {
            max = D_800760D8;
        }
    }
    if ((D_8006A96E & 8) != 0) {
        flag = 1;
        if (max < D_800760DC) {
            max = D_800760DC;
        }
    }

    a0 = D_8006A96E;
    D_8006A96E = a0 & 0xF0;

    if (flag != 0) {
        D_8006A96C = 0x10;
        if (max != 0) {
            func_8002DC68(0xBEB, max | 0x1000);
            D_8006A96E |= 0x10;
            return;
        }
        if ((a0 & 0x10) == 0) {
            return;
        }
        D_800A4F17 = 1;
        func_8002E138(4, 0xBEB, 0);
        v0 = D_800A4F18;
        D_800A4F17 = v0;
        if (v0 != 0) {
            s16 c = D_800A4EFC;
            if (c != 0) {
                D_800A4EFC = c - 1;
            }
            func_80030F80();
            func_8002D320();
            func_80031BE0();
            D_800A4F18 = 0;
            D_800A4F17 = 0;
        }
    } else {
        s16 t = D_8006A96C;
        if (t == 0) {
            return;
        }
        t = t - 1;
        D_8006A96C = t;
        if (t != 0) {
            return;
        }
        if ((a0 & 0x10) == 0) {
            return;
        }
        D_800A4F17 = 1;
        func_8002E138(4, 0xBEB, 0);
        v0 = D_800A4F18;
        D_800A4F17 = v0;
        if (v0 != 0) {
            s16 c = D_800A4EFC;
            if (c != 0) {
                D_800A4EFC = c - 1;
            }
            func_80030F80();
            func_8002D320();
            func_80031BE0();
            D_800A4F18 = 0;
            D_800A4F17 = 0;
        }
    }

    D_800A4F24 = 0;
    D_8006A96E = D_8006A96E & 0xEF;
}
