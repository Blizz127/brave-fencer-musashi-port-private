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

extern void *D_801B6360;
extern s16 *D_801B6364;
extern s32 D_801B6374;
extern s32 D_801B6394;
extern s32 D_801B6398;
extern s32 D_801B639C;
extern void func_8013DD68(void);

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_801B6364 != 0) {
        D_801B6374 = 0;
        p = (int *)(param_1 * 12 + (int)D_801B6360);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801B6394 != x) {
            flag = 1;
            if (D_801B6394 < x) {
                if (x - D_801B6394 < 5) {
                    D_801B6394 = x;
                } else {
                    D_801B6394 = D_801B6394 + 4;
                }
            } else {
                if (D_801B6394 - x < 5) {
                    D_801B6394 = x;
                } else {
                    D_801B6394 = D_801B6394 - 4;
                }
            }
        }
        if (D_801B6398 != y) {
            flag = 1;
            if (D_801B6398 < y) {
                if (y - D_801B6398 < 5) {
                    D_801B6398 = y;
                } else {
                    D_801B6398 = D_801B6398 + 4;
                }
            } else {
                if (D_801B6398 - y < 5) {
                    D_801B6398 = y;
                } else {
                    D_801B6398 = D_801B6398 - 4;
                }
            }
        }
        if (D_801B639C != z) {
            flag = 1;
            if (D_801B639C < z) {
                if (z - D_801B639C < 5) {
                    D_801B639C = z;
                } else {
                    D_801B639C = D_801B639C + 4;
                }
            } else {
                if (D_801B639C - z < 5) {
                    D_801B639C = z;
                } else {
                    D_801B639C = D_801B639C - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801B6374 = flag;
    }
}
