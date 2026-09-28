/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C59C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32, s32);
extern s32 ratan2(s32 x, s32 y);
extern s32 ratan2(s32 dx, s32 dy);

s32 func_8014C59C(void *a0, void *a1) {
    s32 dx = *(s16 *)((s32)a0 + 0x6) - *(s16 *)((s32)a1 + 0x6);
    s32 dy = *(s16 *)((s32)a0 + 0xE) - *(s16 *)((s32)a1 + 0xE);
    return ratan2(dx, dy) & 0xFFF;
}
