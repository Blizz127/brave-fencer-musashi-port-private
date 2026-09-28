/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixY func_8004A0DC
typedef struct { s32 w[8]; } Blk20;

void func_800CAFA0(void *a0) {
    extern u8 D_80078EC1;
    extern Blk20 D_800AE620;
    extern s32 func_80146A6C(s32, void *, s32, s32, s32, s32, s32);
    extern void func_80146C3C();
    extern void RotMatrixY(s32, void *);
    extern s32 func_80047948(s32);
    extern void func_8012F14C(s32, s32, s32);
    extern s32 func_80128ED8(s32, s32 *);

    struct { s16 x, y, z; } sv;
    Blk20 m;
    s32 *s2 = *(s32 **)((s32)a0 + 0x34);
    s32 *s3 = *(s32 **)((s32)a0 + 0x20);

    if (D_80078EC1 != 0x11) {
        func_80146A6C(3, a0, *(s16 *)((s32)a0 + 6), *(s16 *)((s32)a0 + 10), *(s16 *)((s32)a0 + 14), 0xAAAFFFA, 0xE000B400);
        func_80146C3C(a0);
    } else {
        m = D_800AE620;
        RotMatrixY((*(s32 *)((s32)a0 + 0x1C) << 5) + *(s32 *)((s32)a0 + 0x2C), &m);
        m.w[5] = *(s16 *)((s32)s2 + 6);
        m.w[6] = *(s16 *)((s32)s2 + 10);
        m.w[7] = *(s16 *)((s32)s2 + 14);
        sv.x = 0;
        sv.y = (func_80047948(((*(s32 *)((s32)a0 + 0x1C) & 0xF) << 8) + *(s32 *)((s32)a0 + 0x2C)) >> 9) - 0x14;
        sv.z = -0x40;
        func_8012F14C((s32)&m, (s32)&sv, (s32)&sv);
        if (*(s32 *)((s32)a0 + 0x1C) == 0) {
            func_80146A6C(3, a0, sv.x, sv.y, sv.z, 0xAAAFFFA, 0xE000B800);
        } else {
            *(s32 *)((s32)s3 + 4) &= 0x7FFFFFFF;
            *(u16 *)((s32)a0 + 6) = sv.x;
            *(u16 *)((s32)a0 + 10) = sv.y;
            *(u16 *)((s32)a0 + 14) = sv.z;
            func_80128ED8((s32)s3, (s32 *)((s32)a0 + 0x24));
        }
        (*(s32 *)((s32)a0 + 0x1C))++;
    }
}
