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

extern void *D_801A2A20;
extern s16 *D_801A2A24;
extern s32 D_801A2A34;
extern s32 D_801A2A54;
extern s32 D_801A2A58;
extern s32 D_801A2A5C;
extern void func_8013DD68(void);

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_801A2A24 != 0) {
        D_801A2A34 = 0;
        p = (int *)(param_1 * 12 + (int)D_801A2A20);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801A2A54 != x) {
            flag = 1;
            if (D_801A2A54 < x) {
                if (x - D_801A2A54 < 5) {
                    D_801A2A54 = x;
                } else {
                    D_801A2A54 = D_801A2A54 + 4;
                }
            } else {
                if (D_801A2A54 - x < 5) {
                    D_801A2A54 = x;
                } else {
                    D_801A2A54 = D_801A2A54 - 4;
                }
            }
        }
        if (D_801A2A58 != y) {
            flag = 1;
            if (D_801A2A58 < y) {
                if (y - D_801A2A58 < 5) {
                    D_801A2A58 = y;
                } else {
                    D_801A2A58 = D_801A2A58 + 4;
                }
            } else {
                if (D_801A2A58 - y < 5) {
                    D_801A2A58 = y;
                } else {
                    D_801A2A58 = D_801A2A58 - 4;
                }
            }
        }
        if (D_801A2A5C != z) {
            flag = 1;
            if (D_801A2A5C < z) {
                if (z - D_801A2A5C < 5) {
                    D_801A2A5C = z;
                } else {
                    D_801A2A5C = D_801A2A5C + 4;
                }
            } else {
                if (D_801A2A5C - z < 5) {
                    D_801A2A5C = z;
                } else {
                    D_801A2A5C = D_801A2A5C - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801A2A34 = flag;
    }
}
