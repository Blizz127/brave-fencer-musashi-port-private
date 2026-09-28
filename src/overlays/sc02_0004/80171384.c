/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171384 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);
extern s32 func_80012F74(s32 a0, s32 a1, s32 a2, s32 a3);

void func_80171384(void *a0) {
    u8 *p = D_8011F738;
    s32 last;
    s32 sum;
    p[0xC] = func_80012F74(p[0xC], 0, 0xA, 1);
    p[0xD] = func_80012F74(p[0xD], 0, 0xA, 1);
    p[0xE] = func_80012F74(p[0xE], 0, 0xA, 1);
    p[0x1C] = func_80012F74(p[0x1C], 0, 0xA, 1);
    p[0x1D] = func_80012F74(p[0x1D], 0, 0xA, 1);
    p[0x1E] = func_80012F74(p[0x1E], 0, 0xA, 1);
    p[0x2C] = func_80012F74(p[0x2C], 0, 0xA, 1);
    p[0x2D] = func_80012F74(p[0x2D], 0, 0xA, 1);
    last = func_80012F74(p[0x2E], 0, 0xA, 1);
    p[0x2E] = last;
    sum = p[0xC] + p[0xD] + p[0xE] + p[0x1C] + p[0x1D] + p[0x1E] + p[0x2C] + p[0x2D] + (last & 0xff);
    if (sum == 0) {
        func_80171928(a0);
    }
}
