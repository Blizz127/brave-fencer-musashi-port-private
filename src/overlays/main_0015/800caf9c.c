/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF9C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_80161208();
extern u16 func_801487F4(s32 *a0);
extern s32 D_800CBB00[];
extern s32 D_800CBAE0[];
extern s32 func_80148E54(void *a0);
extern s32 func_80012ABC(s32 a0, s32 a1, s32 a2);
extern void func_80148AFC(void *a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp4, s32 sp5, s32 sp6, s32 sp7);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80147324(s32 a0);
extern void func_801655E4(s32 a0);
extern u8 D_80062BD0;
extern void func_80019064(void *a0);
extern s32 func_80165624(s32 a0);

void func_800CAF9C(s32 a0) {
    s32 p;
    u8 v1;
    s16 value;

    p = *(s32 *)(a0 + 0x20);
    *(u32 *)(a0 + 0x44) |= 2;
    if (func_80161208() != 0) {
        return;
    }

    v1 = *(u8 *)(a0 + 0xA9);
    switch (v1) {
    case 0x41:
        value = func_80148E54((void *)a0);
        if (value > 0) {
            *(s16 *)(p + 0x12) = func_80012ABC(*(s16 *)(p + 0x12), value, 4);
        }
        break;
    case 0x53:
    case 0x73:
        func_80148AFC((void *)a0);
        break;
    }

    if (*(u16 *)(a0 + 0xB8) & 0x4000) {
        func_801466F0(2, a0, 0, -0x18, -0xF, 0, 0, 1);
        func_80146A6C(0xF, (void *)a0, 0, -0x18, -0xF, 0, 0);
        func_80147324(0x476);
        func_801655E4(a0);
        func_80019064(&D_80062BD0);
    }

    if (*(u16 *)(a0 + 0xB8) & 0x8000) {
        if (func_80165624(a0) == 0 && (func_801487F4((s32 *)a0) & 0x20)) {
            func_80154274((s32 *)a0, (s32)D_800CBB00);
        } else {
            func_80154274((s32 *)a0, (s32)D_800CBAE0);
            *(u8 *)(a0 + 0x197) += 1;
        }
    }
}
