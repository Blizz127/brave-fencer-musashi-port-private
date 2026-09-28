/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFEC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void);

void func_800CAFEC(s32 *a0) {
    extern s32 D_801151D4;
    extern s16 func_80171AB0(s32 a0, void *a1);
    extern void func_80154150(s32 a0, s32 a1);
    extern void func_80154A74(s32 *a0, s16 a1);
    extern void func_800CB13C(s32 param_1);
    extern void func_80147324(s32 a0);
    extern void func_801553A8(s32 *a0);
    extern void func_80146CA0(void);

    s16 buf[3];
    s32 *p;

    p = (s32 *)D_801151D4;
    buf[0] = (s16)p[0xF];
    buf[1] = (s16)p[0x10];
    buf[2] = (s16)p[0x11];
    if (func_80171AB0((s32)a0, buf) != 0) {
        return;
    }
    func_80154150((s32)a0, 0x1C);
    func_80154A74(a0, 0x19);
    a0[0x234 / 4] = 0;
    func_800CB13C((s32)a0);
    func_80147324(0x8F1);
    func_801553A8(a0);
    ((void (*)(s32))func_80146CA0)((s32)a0);
}
