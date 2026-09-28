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

extern void *D_801EC760;
extern s16 *D_801EC764;
extern s32 D_801EC774;
extern s32 D_801EC794;
extern s32 D_801EC798;
extern s32 D_801EC79C;
extern void func_8013DD68(void);

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_801EC764 != 0) {
        D_801EC774 = 0;
        p = (int *)(param_1 * 12 + (int)D_801EC760);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801EC794 != x) {
            flag = 1;
            if (D_801EC794 < x) {
                if (x - D_801EC794 < 5) {
                    D_801EC794 = x;
                } else {
                    D_801EC794 = D_801EC794 + 4;
                }
            } else {
                if (D_801EC794 - x < 5) {
                    D_801EC794 = x;
                } else {
                    D_801EC794 = D_801EC794 - 4;
                }
            }
        }
        if (D_801EC798 != y) {
            flag = 1;
            if (D_801EC798 < y) {
                if (y - D_801EC798 < 5) {
                    D_801EC798 = y;
                } else {
                    D_801EC798 = D_801EC798 + 4;
                }
            } else {
                if (D_801EC798 - y < 5) {
                    D_801EC798 = y;
                } else {
                    D_801EC798 = D_801EC798 - 4;
                }
            }
        }
        if (D_801EC79C != z) {
            flag = 1;
            if (D_801EC79C < z) {
                if (z - D_801EC79C < 5) {
                    D_801EC79C = z;
                } else {
                    D_801EC79C = D_801EC79C + 4;
                }
            } else {
                if (D_801EC79C - z < 5) {
                    D_801EC79C = z;
                } else {
                    D_801EC79C = D_801EC79C - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801EC774 = flag;
    }
}
