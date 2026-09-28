/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013DBE4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801BD6A4;
extern void *D_801BD690;
extern void func_8013DD68(void);
extern s16 *D_801BD694;
extern s32 D_801BD6C4;
extern s32 D_801BD6C8;
extern s32 D_801BD6CC;

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_801BD694 != 0) {
        D_801BD6A4 = 0;
        p = (int *)(param_1 * 12 + (int)D_801BD690);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801BD6C4 != x) {
            flag = 1;
            if (D_801BD6C4 < x) {
                if (x - D_801BD6C4 < 5) {
                    D_801BD6C4 = x;
                } else {
                    D_801BD6C4 = D_801BD6C4 + 4;
                }
            } else {
                if (D_801BD6C4 - x < 5) {
                    D_801BD6C4 = x;
                } else {
                    D_801BD6C4 = D_801BD6C4 - 4;
                }
            }
        }
        if (D_801BD6C8 != y) {
            flag = 1;
            if (D_801BD6C8 < y) {
                if (y - D_801BD6C8 < 5) {
                    D_801BD6C8 = y;
                } else {
                    D_801BD6C8 = D_801BD6C8 + 4;
                }
            } else {
                if (D_801BD6C8 - y < 5) {
                    D_801BD6C8 = y;
                } else {
                    D_801BD6C8 = D_801BD6C8 - 4;
                }
            }
        }
        if (D_801BD6CC != z) {
            flag = 1;
            if (D_801BD6CC < z) {
                if (z - D_801BD6CC < 5) {
                    D_801BD6CC = z;
                } else {
                    D_801BD6CC = D_801BD6CC + 4;
                }
            } else {
                if (D_801BD6CC - z < 5) {
                    D_801BD6CC = z;
                } else {
                    D_801BD6CC = D_801BD6CC - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801BD6A4 = flag;
    }
}
