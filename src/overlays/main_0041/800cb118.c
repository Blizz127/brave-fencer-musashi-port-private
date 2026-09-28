/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB118 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146E90(s32 *a0, s32 a1);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80162FF4();
extern void func_80162FC0(s32 *a0);
extern s32 func_80146E98(s32 a0);
extern s32 func_801638A0(u8 *a0, s32 a1);
extern s32 func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80163328();
extern s32 func_801632F0();
extern void func_80013E94(void *a0, void *a1);
extern u8 D_80114EB0[];
extern u8 D_80114EC8[];
extern s16 D_80126B18;
extern s16 D_80126B1A;
extern s16 D_80126B1C;

void func_800CB118(s32 a0) {
    s32 sp20[2];
    s32 sp28;
    register s32 ret __asm__("$3");
    register s32 m __asm__("$2");

    func_80162FF4(a0, 0, 0x4000, 0);
    func_80162FC0((s32 *) a0);
    if (func_80146E98(a0) != 0) {
        func_80146CA0((void *) a0);
        return;
    }
    ret = func_801638A0((u8 *) a0, (s32) sp20);
    if (ret == 0) {
    } else if ((m = ret & 0x8000) != 0) {
        *(s32 *)(a0 + 0x2C) = 0;
        *(s32 *)(a0 + 0x24) = 0;
    } else {
        func_80146E90((s32 *) a0, 0x20);
        func_80146CA0((void *) a0);
        return;
    }
    func_80163408(a0, 0x2C, 0x80, 0x200);
    func_80163328(a0);
    switch ((u32) func_801632F0(a0)) {
    case 1:
        func_80013E94(D_80114EB0, &sp28);
        sp28 |= 0x80000000;
        func_80146A6C(0x1F, (void *) a0, D_80126B18, D_80126B1A, D_80126B1C, sp28, 0);
        func_80147324(0x8E6);
        break;
    case 2:
    case 4:
        func_80013E94(D_80114EC8, &sp28);
        sp28 |= 0x80000000;
        func_80146A6C(7, (void *) a0, D_80126B18, D_80126B1A, D_80126B1C, sp28, 0);
        break;
    }
}
