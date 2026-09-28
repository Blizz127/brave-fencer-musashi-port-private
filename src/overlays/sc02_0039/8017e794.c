/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E794 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern u8 D_801202A0[];
extern void func_8017E910(void *a0);

void func_8017E794(void *a0)
{
    s32 i;
    u8 *p;
    u8 *best;
    s16 min_abs;
    s16 best_val;
    u16 counter;

    min_abs = 0x7FFF;
    best_val = 0x7FFF;
    best = 0;
    p = D_801202A0;

    for (i = 0; i < 0x60; i++) {
        if (*(u16 *)(p) == 0x1A8) {
            s16 absdelta;

            func_8017E910(p);
            absdelta = *(s16 *)(p + 0x100);
            if (absdelta < 0) {
                absdelta = -absdelta;
            }
            if (min_abs > absdelta) {
                best_val = *(u16 *)(p + 0x100);
                min_abs = absdelta;
                best = p;
            }
        }
        p += 0x10C;
    }

    counter = *(u16 *)((u8 *)a0 + 0x84);
    counter = counter + 1;
    *(u16 *)((u8 *)a0 + 0x84) = counter;

    if (min_abs < 0xA0) {
        if (*(s32 *)(best + 0xE0) < 0x150) {
            if ((counter & 3) == 0) {
                s32 quotient;
                s32 qc;
                s32 pan;

                quotient = (best_val + 0xA0) / 20;
                pan = 0x7F - (min_abs >> 1);
                qc = (quotient << 8) | 0x3000;
                func_8002D4C8(0x6DA, (pan | qc) & 0xFFFF);
                *(s16 *)((u8 *)a0 + 0x102) = 1;
                return;
            } else {
                return;
            }
        }
    }

    if (*(s16 *)((u8 *)a0 + 0x102) == 1) {
        func_8002D4C8(4, 0x6DA);
        *(s16 *)((u8 *)a0 + 0x102) = 0;
    }
}
