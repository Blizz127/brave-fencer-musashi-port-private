/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012B370 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixYXZ func_80049A1C
extern void RotMatrixYXZ(void *m, void *p);

void func_8012B370(int a0) {
    int q;
    int p;
    q = *(int *)(a0 + 0x20);
    if (q != 0) {
        RotMatrixYXZ((void *)(q + 0x10), (void *)(q + 0x34));
        p = *(int *)(a0 + 0x20);
        *(s16 *)(p + 0x8) = *(u16 *)(a0 + 0x6) + *(u16 *)(a0 + 0x50);
        *(s32 *)(p + 0x48) = *(s16 *)(p + 0x8);
        *(s16 *)(p + 0xA) = *(u16 *)(a0 + 0xA) + *(u16 *)(a0 + 0x52);
        *(s32 *)(p + 0x4C) = *(s16 *)(p + 0xA);
        {
            u16 e = *(u16 *)(a0 + 0xE);
            u16 t2c = *(u16 *)(p + 0x2C) | 0x1;
            s16 sum = e + *(u16 *)(a0 + 0x54);
            *(s16 *)(p + 0xC) = sum;
            *(u16 *)(p + 0x2C) = t2c;
            *(s32 *)(p + 0x50) = sum;
        }
    }
}
