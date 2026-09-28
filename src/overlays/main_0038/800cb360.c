/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB360 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146CA0(void *a0);

void func_800CB360(void *arg0) {
    s32 unk60;
    u8 mat[0x40];

    extern s32 func_80146E98(s32 a0);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern void func_80146CA0(void *a0);
    extern void func_80013F3C(void *a0);
    extern void func_800126C4(void *a0, s32 a1);
    extern void func_800123F0(void *a0, s32 a1);
    extern void func_80012558(void *a0, s32 a1);
    extern void func_80163194(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
    extern void func_80162FC0(s32 *a0);
    extern s32 func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
    extern void func_80163328(void *a0);
    extern s32 func_801632F0(void *a0);
    extern void func_80013E94(void *a0, void *a1);
    extern s16 D_80126B18[];
    extern u8 D_80114EB0[];
    extern u8 D_80114EC8[];

    s32 v1 = *(u32 *)((s32)arg0 + 0x20);
    *(u16 *)(v1 + 0x14) += 0x200;
    if (func_80146E98((s32)arg0)) {
        func_80146A6C(3, arg0, *(s16 *)((s32)arg0 + 6), *(s16 *)((s32)arg0 + 0xA),
                      *(s16 *)((s32)arg0 + 0xE), 0, 0x1C00);
    } else {
        register void *r16 __asm__("$16") = mat + 0x20;
        u32 ret;
        s32 id;
        func_80013F3C(r16);
        func_800126C4(r16, *(s16 *)((s32)arg0 + 0x60));
        func_800123F0(r16, *(s16 *)((s32)arg0 + 0x62));
        func_80012558(r16, *(s16 *)((s32)arg0 + 0x64));
        func_80163194((s32)arg0, 0, 0, 0, (s32)r16);
        func_80162FC0((s32 *)arg0);
        func_80163408((s32)arg0, 0x2D, 0x80, 0x200);
        func_80163328(arg0);
        ret = func_801632F0(arg0);
        switch (ret) {
        case 1:
            func_80013E94(D_80114EB0, &unk60);
            id = 0x1F;
            break;
        case 2:
        case 4:
            func_80013E94(D_80114EC8, &unk60);
            id = 7;
            break;
        default:
            return;
        }
        unk60 |= 0x80000000;
        func_80146A6C(id, arg0, D_80126B18[0], D_80126B18[1], D_80126B18[2], unk60, 0);
    }
    func_80146CA0(arg0);
}
