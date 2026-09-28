/* Overlay range [80138C60,80138D58) from MAIN.CD member 0012.
 * SHA256(span)=06c15678d5b582e4b6c8bfe78c85a0a5494eb8eecc5ef23bf652049ef7be6ad0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80138C60 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
        u8 b0;
        u8 b1;
        u8 b2;
        u8 b3;
    } Q_80138C60;
extern void func_80139BE0(s32 a0);
extern void func_80139C7C(u8 *a0);
extern s32 func_8013A8FC(s32 arg0);

s32 func_80138C60(s32 arg0)
{
    extern Q_80138C60 D_8017E950[];
    u16 t;
    u8 b;
    s32 f;
    s32 idx;

    if (*(s32 *)(arg0 + 8) & 0x2000) {
        return 1;
    }

    t = *(u8 *)(arg0 + 0x22) & 7;
    *(s16 *)(arg0 + 0x18) = t;
    if (t < 2) {
        *(u8 *)(arg0 + 0x20) = 0;
    }

    f = *(s32 *)(arg0 + 8);
    if (f & 0x40) {
        *(u8 *)(arg0 + 0x22) = (*(u8 *)(arg0 + 0x22) & 0x67) | (f & ~0x67);
    }

    b = *(u8 *)(arg0 + 0x22);
    if (b & 0x80) {
        idx = (b & 0x18) >> 3;
    } else {
        idx = (b & 0x78) >> 3;
        if (b & 0x60) {
            *(s16 *)(arg0 + 0x1C) = 0;
        }
    }

    *(Q_80138C60 *)(arg0 + 0x24) = D_8017E950[idx];

    func_80139BE0(arg0);
    func_80139C7C((u8 *)arg0);
    return func_8013A8FC(arg0);
}
