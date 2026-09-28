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

extern void *D_80199848;
extern s16 *D_8019984C;
extern s32 D_8019985C;
extern s32 D_8019987C;
extern s32 D_80199880;
extern s32 D_80199884;
extern void func_8013DD68(void);

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_8019984C != 0) {
        D_8019985C = 0;
        p = (int *)(param_1 * 12 + (int)D_80199848);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_8019987C != x) {
            flag = 1;
            if (D_8019987C < x) {
                if (x - D_8019987C < 5) {
                    D_8019987C = x;
                } else {
                    D_8019987C = D_8019987C + 4;
                }
            } else {
                if (D_8019987C - x < 5) {
                    D_8019987C = x;
                } else {
                    D_8019987C = D_8019987C - 4;
                }
            }
        }
        if (D_80199880 != y) {
            flag = 1;
            if (D_80199880 < y) {
                if (y - D_80199880 < 5) {
                    D_80199880 = y;
                } else {
                    D_80199880 = D_80199880 + 4;
                }
            } else {
                if (D_80199880 - y < 5) {
                    D_80199880 = y;
                } else {
                    D_80199880 = D_80199880 - 4;
                }
            }
        }
        if (D_80199884 != z) {
            flag = 1;
            if (D_80199884 < z) {
                if (z - D_80199884 < 5) {
                    D_80199884 = z;
                } else {
                    D_80199884 = D_80199884 + 4;
                }
            } else {
                if (D_80199884 - z < 5) {
                    D_80199884 = z;
                } else {
                    D_80199884 = D_80199884 - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_8019985C = flag;
    }
}
