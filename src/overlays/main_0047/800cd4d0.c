/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD4D0 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_800CCDE8();

void func_800CD4D0(void *arg0) {
    extern s32 D_8011D030;
    extern u8 D_800CD6E0[];
    extern void func_80146C3C(void);
    extern void func_80016714(void *a0, s32 a1);

    unsigned short *p;
    short i;
    s32 k;

    *(s32 *)((s32)arg0 + 0x2C) = 0;
    i = 0;
    p = (unsigned short *)&D_8011D030;
    k = 0x3B;
    do {
        if (p != (unsigned short *)arg0) {
            if (*p == k) {
                ((void (*)(unsigned short *))func_80146C3C)(p);
            }
        }
        i = i + 1;
        p = p + 0x2C;
    } while (i < 0x1E);

    func_80016714(D_800CD6E0, 0xC4);
    func_800CCDE8(arg0, 0, 0);
    *(u16 *)((s32)arg0 + 2) = *(u16 *)((s32)arg0 + 2) + 1;
}
