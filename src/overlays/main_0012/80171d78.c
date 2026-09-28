/* Overlay range [80171D78,80171E08) from MAIN.CD member 0012.
 * SHA256(span)=f376036dbe421c61acda785f6bfe19b54f6f71047378740419a81e6d4c52c45b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171D78 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);
extern void func_80146D90(s32 a0);
extern s32 ratan2(s32 dx, s32 dy);
extern void func_80146D90(int);
extern void func_80146D90(s32);
extern s32 ratan2(s32, s32);
extern s32 func_8017248C(s32 a0, s32 a1);
extern void func_80171EC8(s32 a0);

s32 func_80171D78(s32 a0, s32 a1)
{
    s32 ret;
    s32 ang;
    s32 p;
    ret = func_8017248C(a0, a1);
    if (ret != 0) {
        func_80146D90(a0);
        return ret;
    }
    ang = ratan2(*(s16 *)(a1 + 0) - *(s16 *)(a0 + 6),
                 *(s16 *)(a1 + 4) - *(s16 *)(a0 + 0xE));
    ang = (ang + 0x800) & 0xFFF;
    p = *(s32 *)(a0 + 0x20);
    *(s16 *)(p + 0x12) = ang;
    func_80171EC8(a0);
    return 0;
}
