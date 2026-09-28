/* Exact retail word export for [80034DFC,8003500C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80034DFC - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_8006AEF5;
extern s32 D_8006AEF8;
extern s32 D_8006AEFC;
extern u8 D_80076118[];

void func_80034DFC(short arg0) {
    u8 *cur;
    u8 *src;
    u8 saved;
    s32 i;
    s32 next;
    s32 nn;

    if (arg0 == 0) {
        return;
    }
    i = (short)(arg0 - 1);
    cur = D_80076118 + i * 0x30;
    saved = D_8006AEF5;
    D_8006AEF5 = 1;
    if (cur[0] != 0) {
        cur[0] = 0;
        cur[1] = 1;
        if (i != D_8006AEF8 && cur[7] != 0) {
            next = i + 1;
            goto check;
            for (;;) {
                src = D_80076118 + next * 0x30;
                cur[0] = src[0];
                cur[1] = src[1];
                cur[2] = src[2];
                cur[3] = src[3];
                cur[4] = src[4];
                cur[5] = src[5];
                cur[6] = src[6];
                cur[7] = src[7];
                *(s32 *)(cur + 0x08) = *(s32 *)(src + 0x08);
                *(s32 *)(cur + 0x0C) = *(s32 *)(src + 0x0C);
                *(s32 *)(cur + 0x10) = *(s32 *)(src + 0x10);
                *(s32 *)(cur + 0x14) = *(s32 *)(src + 0x14);
                *(s32 *)(cur + 0x18) = *(s32 *)(src + 0x18);
                *(s32 *)(cur + 0x1C) = *(s32 *)(src + 0x1C);
                *(s32 *)(cur + 0x20) = *(s32 *)(src + 0x20);
                *(s32 *)(cur + 0x24) = *(s32 *)(src + 0x24);
                nn = next + 1;
                *(s32 *)(cur + 0x28) = *(s32 *)(src + 0x28);
                *(s32 *)(cur + 0x2C) = *(s32 *)(src + 0x2C);
                ((void (*)(s32, s32)) *(s32 *)(src + 0x28))(nn, i + 1);
                i = next;
                cur = src;
                next = nn;
            check:
                if (next >= 4) {
                    next = 0;
                }
                if (next == D_8006AEFC) {
                    break;
                }
            }
            D_8006AEFC = i;
            D_80076118[i * 0x30] = 0;
        }
    }
    D_8006AEF5 = saved;
}
