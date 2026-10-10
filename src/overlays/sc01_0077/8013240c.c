/* Overlay range [8013240C,801325B8) from MAIN.CD member 0012.
 * SHA256(span)=1d8a59c7470fb38abe13ee68f6efc3c56bd23947a322a1094e951025c6fad560.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8013240C - 107 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_801325B8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_8013240C(s32 a0) {
    s32 *node;
    s32 ent;
    s32 v;
    s16 h6;
    ent = *(s32 *)(a0 + 0x0) + (*(s16 *)(a0 + 0x4) << 3);
    node = (s32 *)*(s32 *)(ent + 0);
    *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0xC) & 0xFFFF3FFF;
    if ((s32)node == -1) {
        *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0xC) | 0x4000;
        return;
    }
    if (*(s16 *)(ent + 0x6) < 0) {
        v = 0x1000 - ((*(s16 *)(a0 + 0x6) << 12) / *(s16 *)(ent + 0x4));
    } else {
        v = (*(s16 *)(a0 + 0x6) << 12) / *(s16 *)(ent + 0x4);
    }
    func_801325B8(*(s32 *)(a0 + 0x8), node[0], node[1], node[2], v);
    h6 = *(s16 *)(ent + 0x6);
    if (h6 < 0) {
        *(s16 *)(a0 + 0x6) = *(u16 *)(a0 + 0x6) - h6;
    } else {
        *(s16 *)(a0 + 0x6) = *(u16 *)(a0 + 0x6) + h6;
    }
    if (*(s16 *)(a0 + 0x6) < *(s16 *)(ent + 0x4)) {
        return;
    }
    *(s16 *)(a0 + 0x6) = 0;
    *(s16 *)(a0 + 0x4) = *(u16 *)(a0 + 0x4) + 1;
    {
        s32 *p = (s32 *)((*(s16 *)(a0 + 0x4) << 3) + *(s32 *)(a0 + 0x0));
        s32 w = p[0];
        s32 c;
        if (w != -1) {
            if (w != 0) {
                return;
            }
            *(s16 *)(a0 + 0x4) = 0;
            c = *(s32 *)(a0 + 0xC) | 0x8000;
        } else {
            c = *(s32 *)(a0 + 0xC) | 0x4000;
        }
        *(s32 *)(a0 + 0xC) = c;
    }
}
