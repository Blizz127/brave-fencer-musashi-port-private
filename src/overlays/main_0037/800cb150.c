/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB150 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB358(void);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80162FF4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80162FC0(void *a0);
extern s32 func_80146E98(s32 a0);
extern s32 func_80163950(s32 a0);
extern s32 func_8016380C(void *a0, s32 a1);
extern void func_80016714(s8 *a0, s32 a1);
extern void func_80146578(void);
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80163328(void *a0);
extern u8 D_800CB628[];

void func_800CB150(void *a0) {
    s32 sp20;
    s32 flags;
    s32 sh;
    s32 t;

    func_80162FF4((s32)a0, 0, 0x40000, 0);
    func_80162FC0(a0);
    if (func_80146E98((s32)a0) != 0) {
        func_80146CA0(a0);
        return;
    }
    flags = func_80163950((s32)a0) != 0;
    sh = flags << 13;
    t = sh | func_8016380C(a0, (s32)&sp20);
    if (t == 0) {
        goto tail;
    }
    if (t != 0x8000) {
        goto alloc;
    }
    *(s32 *)((s32)a0 + 0x2C) = 0;
    *(s32 *)((s32)a0 + 0x24) = 0;
    goto tail;
alloc:
    func_80016714(*(s8 **)((s32)a0 + 0x20), 0x84);
    *(s32 *)((s32)a0 + 0x20) = 0;
    t = ((s32 (*)(void))func_80146578)();
    *(s32 *)((s32)a0 + 0x20) = t;
    if (t != 0) {
        func_8001CB6C((u8 *)t, (s32)D_800CB628, 0x1A0, 0x100);
        *(u8 *)((s32)t + 0x27) = 0x1B;
        *(u16 *)((s32)t + 0x10) = 0x400;
        func_80146E90((s32 *)a0, 0x20);
        for (t = 0; t < 4; t++) {
            func_80146A6C(0x45, a0, *(s16 *)((s32)a0 + 6), *(s16 *)((s32)a0 + 0xA),
                          *(s16 *)((s32)a0 + 0xE), t, 0);
        }
        func_80147324(0x913);
        func_80146CA0(a0);
        return;
    }
    ((void (*)(s32))func_800CB358)(a0);
tail:
    func_80163408((s32)a0, 0x27, 0, 0x80);
    ((void (*)(s32))func_80163328)(a0);
}
