/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013DBE4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8019FA54;
extern void *D_8019FA40;
extern void func_8013DD68(void);
extern s16 *D_8019FA44;
extern s32 D_8019FA74;
extern s32 D_8019FA78;
extern s32 D_8019FA7C;

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_8019FA44 != 0) {
        D_8019FA54 = 0;
        p = (int *)(param_1 * 12 + (int)D_8019FA40);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_8019FA74 != x) {
            flag = 1;
            if (D_8019FA74 < x) {
                if (x - D_8019FA74 < 5) {
                    D_8019FA74 = x;
                } else {
                    D_8019FA74 = D_8019FA74 + 4;
                }
            } else {
                if (D_8019FA74 - x < 5) {
                    D_8019FA74 = x;
                } else {
                    D_8019FA74 = D_8019FA74 - 4;
                }
            }
        }
        if (D_8019FA78 != y) {
            flag = 1;
            if (D_8019FA78 < y) {
                if (y - D_8019FA78 < 5) {
                    D_8019FA78 = y;
                } else {
                    D_8019FA78 = D_8019FA78 + 4;
                }
            } else {
                if (D_8019FA78 - y < 5) {
                    D_8019FA78 = y;
                } else {
                    D_8019FA78 = D_8019FA78 - 4;
                }
            }
        }
        if (D_8019FA7C != z) {
            flag = 1;
            if (D_8019FA7C < z) {
                if (z - D_8019FA7C < 5) {
                    D_8019FA7C = z;
                } else {
                    D_8019FA7C = D_8019FA7C + 4;
                }
            } else {
                if (D_8019FA7C - z < 5) {
                    D_8019FA7C = z;
                } else {
                    D_8019FA7C = D_8019FA7C - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_8019FA54 = flag;
    }
}
