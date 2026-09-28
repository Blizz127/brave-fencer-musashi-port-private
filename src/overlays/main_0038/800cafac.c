/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFAC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_80161208();
extern u16 func_801487F4(s32 *a0);
extern u8 D_800CBB84[];
extern u8 D_800CBB64[];
extern s16 func_80148E54(void *a0);
extern s16 func_80012ABC(s16 a0, s16 a1, s32 a2);
extern void func_80148AFC(void *a0);
extern void func_801466F0(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80147324(s32 a0);
extern void func_801655E4(void *a0);
extern s32 func_80165624(void *a0);

void func_800CAFAC(void *a0) {
    s32 temp = *(s32 *)((u8 *)a0 + 0x20);
    *(u32 *)((u8 *)a0 + 0x44) |= 2;
    if (func_80161208() == 0) {
        switch (*(u8 *)((u8 *)a0 + 0xA9)) {
        case 0x41: {
            s16 r = func_80148E54(a0);
            if (r > 0) {
                *(s16 *)(temp + 0x12) = func_80012ABC(*(s16 *)(temp + 0x12), r, 4);
            }
            break;
        }
        case 0x53:
        case 0x73:
            func_80148AFC(a0);
            break;
        }
        if (*(u16 *)((u8 *)a0 + 0xB8) & 0x4000) {
            s32 mf = -0xF;
            s32 one = 1;
            func_801466F0(0x1F, a0, 0, -0x18, mf, 0, 0, one);
            func_801466F0(0x1F, a0, 0, -0x18, mf, one, 0, one);
            func_801466F0(0x1F, a0, 0, -0x18, mf, 2, 0, one);
            func_80146A6C(0x43, a0, 0, -0x18, mf, 0, 0);
            func_80147324(0xA64);
            func_801655E4(a0);
        }
        if (*(u16 *)((u8 *)a0 + 0xB8) & 0x8000) {
            if (func_80165624(a0) == 0 && (func_801487F4((s32 *)a0) & 0x20)) {
                func_80154274((s32 *)a0, (s32)D_800CBB84);
            } else {
                func_80154274((s32 *)a0, (s32)D_800CBB64);
                *(u8 *)((u8 *)a0 + 0x197) += 1;
            }
        }
    }
}
