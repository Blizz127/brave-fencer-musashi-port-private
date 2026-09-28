/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014E284 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
typedef struct EntSC01077 {
    u16 f00;
    u8  pad02[4];
    u16 f06;
    u8  pad08[2];
    u16 f0A;
    u8  pad0C[2];
    u16 f0E;
    u8  pad10[0x10];
    s32 f20;
    u8  pad24[0x34];
    s32 f58;
    u16 f5C;
    u8  pad5E[0xAE];
} EntSC01077;
extern s32 ratan2(s32 a0, s32 a1);
extern s32 func_80012A60(s32 a0, s32 a1);
extern s32 ratan2(s32, s32);
extern u8 D_801202A0[];
extern s32 ratan2(s32 x, s32 y);
extern s32 ratan2(s32 dx, s32 dy);
extern int func_80135A4C();
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);

s32 func_8014E284(s32 a0, s16 *arg1, s16 *arg2) {
    u16 *a1 = (u16 *)arg1;
    u16 *a2 = (u16 *)arg2;
    EntSC01077 *p;
    s16 dx;
    s16 dz;
    s16 ax;
    s16 az;
    s32 r1;
    s32 r2;
    dx = a2[0] - a1[0];
    dz = a2[2] - a1[2];
    if ((s16)(dx | dz) != 0) {
        for (p = (EntSC01077 *)D_801202A0; p < (EntSC01077 *)D_801202A0 + 96; p++) {
            if (p->f00 == 0) continue;
            if (p->f58 == 0) continue;
            if ((p->f5C & 0x1000) == 0) continue;
             
            if (((s32 (*)(s32, s32, u16 *, u16 *))func_80135A4C)(p->f20, p->f58, a1, a2) == 0) continue;
            ax = p->f06 - *(u16 *)(a0 + 6);
            az = p->f0E - *(u16 *)(a0 + 0xE);
            r1 = (s16)ratan2(dz, dx);
            r2 = (s16)ratan2(az, ax);
            if ((s16)func_80012A60(r1, r2) < 0x400) {
                *(s32 *)(a0 + 0x170) = (s32)p;
                *(u16 *)(a0 + 6) = a2[0];
                *(u16 *)(a0 + 0xA) = a2[1] + 0x10;
                *(u16 *)(a0 + 0xE) = a2[2];
                return 1;
            }
        }
    }
    return 0;
}
