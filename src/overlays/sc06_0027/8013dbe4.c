/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013DBE4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *D_8019C070;
extern s16 *D_8019C074;
extern s32 D_8019C084;
extern s32 D_8019C0A4;
extern s32 D_8019C0A8;
extern s32 D_8019C0AC;
extern void func_8013DD68(void);

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_8019C074 != 0) {
        D_8019C084 = 0;
        p = (int *)(param_1 * 12 + (int)D_8019C070);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_8019C0A4 != x) {
            flag = 1;
            if (D_8019C0A4 < x) {
                if (x - D_8019C0A4 < 5) {
                    D_8019C0A4 = x;
                } else {
                    D_8019C0A4 = D_8019C0A4 + 4;
                }
            } else {
                if (D_8019C0A4 - x < 5) {
                    D_8019C0A4 = x;
                } else {
                    D_8019C0A4 = D_8019C0A4 - 4;
                }
            }
        }
        if (D_8019C0A8 != y) {
            flag = 1;
            if (D_8019C0A8 < y) {
                if (y - D_8019C0A8 < 5) {
                    D_8019C0A8 = y;
                } else {
                    D_8019C0A8 = D_8019C0A8 + 4;
                }
            } else {
                if (D_8019C0A8 - y < 5) {
                    D_8019C0A8 = y;
                } else {
                    D_8019C0A8 = D_8019C0A8 - 4;
                }
            }
        }
        if (D_8019C0AC != z) {
            flag = 1;
            if (D_8019C0AC < z) {
                if (z - D_8019C0AC < 5) {
                    D_8019C0AC = z;
                } else {
                    D_8019C0AC = D_8019C0AC + 4;
                }
            } else {
                if (D_8019C0AC - z < 5) {
                    D_8019C0AC = z;
                } else {
                    D_8019C0AC = D_8019C0AC - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_8019C084 = flag;
    }
}
