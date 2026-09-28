/* Overlay range [8017AD0C,8017ADE8) from MAIN.CD member 0012.
 * SHA256(span)=45e2bcb084979fd87e6fe1b87bdb4221fffa70af65ab0a47a652930408f89567.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017AD0C - byte-exact against retail at -O2 (tools/register_match.py). */
#define MoveImage func_80059A80
typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Rect;
extern void MoveImage(void *a0, s32 a1, s32 a2);

s32 func_8017AD0C(s32 arg0)
{
    Rect rect;
    s32 var_v0;
    s32 var_v1;
    arg0 = arg0 - 1;
    rect.x = ((arg0 & 3) * 0x10) + 0x280;
    var_v0 = arg0;
    if (arg0 < 0) {
        var_v0 = arg0 + 3;
    }
    rect.y = (var_v0 >> 2) + 0x1F8;
    rect.w = 0x10;
    rect.h = 1;
    MoveImage(&rect, 0x160, 0x1C9);
    if (arg0 == 0x18) {
        rect.x = 0x2C0;
        rect.y = 0x1D0;
    } else {
        rect.x = ((arg0 & 7) * 8) + 0x280;
        var_v1 = arg0;
        if (arg0 < 0) {
            var_v1 = arg0 + 7;
        }
        rect.y = (var_v1 >> 3) * 0x28 + 0x180;
    }
    rect.w = 0x20;
    rect.h = 0x28;
    __asm__ __volatile__("" ::: "memory");
    MoveImage(&rect, 0x1C8, 0x190);
}
