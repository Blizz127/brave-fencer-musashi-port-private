/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013DBE4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80195024;
extern void *D_80195010;
extern void func_8013DD68(void);
extern s16 *D_80195014;
extern s32 D_80195044;
extern s32 D_80195048;
extern s32 D_8019504C;

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_80195014 != 0) {
        D_80195024 = 0;
        p = (int *)(param_1 * 12 + (int)D_80195010);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_80195044 != x) {
            flag = 1;
            if (D_80195044 < x) {
                if (x - D_80195044 < 5) {
                    D_80195044 = x;
                } else {
                    D_80195044 = D_80195044 + 4;
                }
            } else {
                if (D_80195044 - x < 5) {
                    D_80195044 = x;
                } else {
                    D_80195044 = D_80195044 - 4;
                }
            }
        }
        if (D_80195048 != y) {
            flag = 1;
            if (D_80195048 < y) {
                if (y - D_80195048 < 5) {
                    D_80195048 = y;
                } else {
                    D_80195048 = D_80195048 + 4;
                }
            } else {
                if (D_80195048 - y < 5) {
                    D_80195048 = y;
                } else {
                    D_80195048 = D_80195048 - 4;
                }
            }
        }
        if (D_8019504C != z) {
            flag = 1;
            if (D_8019504C < z) {
                if (z - D_8019504C < 5) {
                    D_8019504C = z;
                } else {
                    D_8019504C = D_8019504C + 4;
                }
            } else {
                if (D_8019504C - z < 5) {
                    D_8019504C = z;
                } else {
                    D_8019504C = D_8019504C - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_80195024 = flag;
    }
}
