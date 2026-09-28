/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013240C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801325B8(int a0, int a1, int a2, int a3, int a4);
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
