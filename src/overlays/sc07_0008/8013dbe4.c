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

extern void *D_80195390;
extern s16 *D_80195394;
extern s32 D_801953A4;
extern s32 D_801953C4;
extern s32 D_801953C8;
extern s32 D_801953CC;
extern void func_8013DD68(void);

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_80195394 != 0) {
        D_801953A4 = 0;
        p = (int *)(param_1 * 12 + (int)D_80195390);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801953C4 != x) {
            flag = 1;
            if (D_801953C4 < x) {
                if (x - D_801953C4 < 5) {
                    D_801953C4 = x;
                } else {
                    D_801953C4 = D_801953C4 + 4;
                }
            } else {
                if (D_801953C4 - x < 5) {
                    D_801953C4 = x;
                } else {
                    D_801953C4 = D_801953C4 - 4;
                }
            }
        }
        if (D_801953C8 != y) {
            flag = 1;
            if (D_801953C8 < y) {
                if (y - D_801953C8 < 5) {
                    D_801953C8 = y;
                } else {
                    D_801953C8 = D_801953C8 + 4;
                }
            } else {
                if (D_801953C8 - y < 5) {
                    D_801953C8 = y;
                } else {
                    D_801953C8 = D_801953C8 - 4;
                }
            }
        }
        if (D_801953CC != z) {
            flag = 1;
            if (D_801953CC < z) {
                if (z - D_801953CC < 5) {
                    D_801953CC = z;
                } else {
                    D_801953CC = D_801953CC + 4;
                }
            } else {
                if (D_801953CC - z < 5) {
                    D_801953CC = z;
                } else {
                    D_801953CC = D_801953CC - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801953A4 = flag;
    }
}
