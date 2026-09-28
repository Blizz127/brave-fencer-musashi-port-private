/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013DBE4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8018F0FC;
extern void *D_8018F0E8;
extern void func_8013DD68(void);
extern s16 *D_8018F0EC;
extern s32 D_8018F11C;
extern s32 D_8018F120;
extern s32 D_8018F124;

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;

    if (D_8018F0EC != 0) {
        D_8018F0FC = 0;
        p = (int *)(param_1 * 12 + (int)D_8018F0E8);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_8018F11C != x) {
            flag = 1;
            if (D_8018F11C < x) {
                if (x - D_8018F11C < 5) {
                    D_8018F11C = x;
                } else {
                    D_8018F11C = D_8018F11C + 4;
                }
            } else {
                if (D_8018F11C - x < 5) {
                    D_8018F11C = x;
                } else {
                    D_8018F11C = D_8018F11C - 4;
                }
            }
        }
        if (D_8018F120 != y) {
            flag = 1;
            if (D_8018F120 < y) {
                if (y - D_8018F120 < 5) {
                    D_8018F120 = y;
                } else {
                    D_8018F120 = D_8018F120 + 4;
                }
            } else {
                if (D_8018F120 - y < 5) {
                    D_8018F120 = y;
                } else {
                    D_8018F120 = D_8018F120 - 4;
                }
            }
        }
        if (D_8018F124 != z) {
            flag = 1;
            if (D_8018F124 < z) {
                if (z - D_8018F124 < 5) {
                    D_8018F124 = z;
                } else {
                    D_8018F124 = D_8018F124 + 4;
                }
            } else {
                if (D_8018F124 - z < 5) {
                    D_8018F124 = z;
                } else {
                    D_8018F124 = D_8018F124 - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_8018F0FC = flag;
    }
}
