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

extern void *D_801A44D0;
extern s16 *D_801A44D4;
extern s32 D_801A44E4;
extern s32 D_801A4504;
extern s32 D_801A4508;
extern s32 D_801A450C;
extern void func_8013DD68(void);

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_801A44D4 != 0) {
        D_801A44E4 = 0;
        p = (int *)(param_1 * 12 + (int)D_801A44D0);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801A4504 != x) {
            flag = 1;
            if (D_801A4504 < x) {
                if (x - D_801A4504 < 5) {
                    D_801A4504 = x;
                } else {
                    D_801A4504 = D_801A4504 + 4;
                }
            } else {
                if (D_801A4504 - x < 5) {
                    D_801A4504 = x;
                } else {
                    D_801A4504 = D_801A4504 - 4;
                }
            }
        }
        if (D_801A4508 != y) {
            flag = 1;
            if (D_801A4508 < y) {
                if (y - D_801A4508 < 5) {
                    D_801A4508 = y;
                } else {
                    D_801A4508 = D_801A4508 + 4;
                }
            } else {
                if (D_801A4508 - y < 5) {
                    D_801A4508 = y;
                } else {
                    D_801A4508 = D_801A4508 - 4;
                }
            }
        }
        if (D_801A450C != z) {
            flag = 1;
            if (D_801A450C < z) {
                if (z - D_801A450C < 5) {
                    D_801A450C = z;
                } else {
                    D_801A450C = D_801A450C + 4;
                }
            } else {
                if (D_801A450C - z < 5) {
                    D_801A450C = z;
                } else {
                    D_801A450C = D_801A450C - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801A44E4 = flag;
    }
}
