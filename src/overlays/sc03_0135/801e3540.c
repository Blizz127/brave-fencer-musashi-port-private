/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E3540 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80024054(u8 *, u8 *);
extern s32 func_800D2650(s32, u8 *, s16, s16, s32, s32);
extern s32 func_800D27DC(s32, s32, void *, s16, s32);
extern s32 func_800D29F8(s32, s32, void *, s16, s32);
extern s32 func_801E3830(s32, s16, s16, s16, s32 *);

s32 func_801E3540(s32 ot, u8 *s, s16 c) {

    extern u16 D_8011511A;
    extern u8  D_801E6584[];
    extern s32 *D_801E64FC[];
    u8  sp18[72];
    s32 sp60[5];
    s32 sp78[8];
    s32 flag;
    s32 dim;
    s32 dim2;
    register s32 dim3 __asm__("$16");
    s32 t;
    s16 i;
    s16 k;
    s32 *p;
    u8 *bp;
    s16 *q;
    s32 r;
    s32 mode;

    if (c == 0) {
        flag = 0;
    } else {
        flag = -(D_8011511A != c) & 0xFF;
    }

    t = *(s32 *)(s + 0x14);
    if (t < 0) {
        func_80024054((u8 *)t, sp18);
        ot = func_800D2650(ot, sp18, *(s16 *)(s + 0x10), *(s16 *)(s + 0x12), 1,
                           flag ? 0x585858 : 0x808080);
    } else {
        p = D_801E64FC[t];
        for (k = 0; k < D_801E6584[*(s32 *)(s + 0x14)]; k++) {
            bp = sp18;
            dim = flag;
            for (i = 0; i < 5; i++) {
                if (i == 0) {
                    sp60[0] = (((s16 *)p)[0] + *(s16 *)(s + 0x10)) & 0xFFFF |
                              ((((s16 *)p)[1] + *(s16 *)(s + 0x12)) << 16);
                } else {
                    *(s32 *)(bp + 0x48 + i * 4) = p[i];
                }
            }
            mode = dim ? 3 : 2;
            do {
                ot = func_800D27DC(mode, ot, sp60, 1, 0);
            } while (0);
            p += 5;
        }
    }

    i = 0;
    q = *(s16 **)(s + 0x18);
    dim2 = flag;
    for (;;) {
        r = func_801E3830(*(s32 *)(s + 0x1C), *(s16 *)s, c, i++, sp78);
        if (r == 0) {
            break;
        }
        if (r < 0) {
            func_80024054((u8 *)r, sp18);
            if (dim2 != 0) {
                sp78[0] = 0x585858;
            }
            ot = func_800D2650(ot, sp18, q[0], q[1], 1, sp78[0]);
        } else {
            p = D_801E64FC[r];
            *p = (u16)q[0] | (q[1] << 16);
            ot = func_800D27DC(dim2 ? 3 : 2, ot, p, 1, 0);
        }
        q += 2;
    }

    dim3 = flag;
    return func_800D29F8(dim3,
                         func_800D27DC(dim3 != 0, ot, (void *)*(s32 *)(s + 4),
                                       *(s16 *)(s + 0xC), 0),
                         (void *)*(s32 *)(s + 8), *(s16 *)(s + 0xE), 0);
}
