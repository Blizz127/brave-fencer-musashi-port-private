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

extern void *D_8019BE20;
extern s16 *D_8019BE24;
extern s32 D_8019BE34;
extern s32 D_8019BE54;
extern s32 D_8019BE58;
extern s32 D_8019BE5C;
extern void func_8013DD68(void);

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_8019BE24 != 0) {
        D_8019BE34 = 0;
        p = (int *)(param_1 * 12 + (int)D_8019BE20);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_8019BE54 != x) {
            flag = 1;
            if (D_8019BE54 < x) {
                if (x - D_8019BE54 < 5) {
                    D_8019BE54 = x;
                } else {
                    D_8019BE54 = D_8019BE54 + 4;
                }
            } else {
                if (D_8019BE54 - x < 5) {
                    D_8019BE54 = x;
                } else {
                    D_8019BE54 = D_8019BE54 - 4;
                }
            }
        }
        if (D_8019BE58 != y) {
            flag = 1;
            if (D_8019BE58 < y) {
                if (y - D_8019BE58 < 5) {
                    D_8019BE58 = y;
                } else {
                    D_8019BE58 = D_8019BE58 + 4;
                }
            } else {
                if (D_8019BE58 - y < 5) {
                    D_8019BE58 = y;
                } else {
                    D_8019BE58 = D_8019BE58 - 4;
                }
            }
        }
        if (D_8019BE5C != z) {
            flag = 1;
            if (D_8019BE5C < z) {
                if (z - D_8019BE5C < 5) {
                    D_8019BE5C = z;
                } else {
                    D_8019BE5C = D_8019BE5C + 4;
                }
            } else {
                if (D_8019BE5C - z < 5) {
                    D_8019BE5C = z;
                } else {
                    D_8019BE5C = D_8019BE5C - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_8019BE34 = flag;
    }
}
