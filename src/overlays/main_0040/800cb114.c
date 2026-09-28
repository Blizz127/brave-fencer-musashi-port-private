/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB114 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB3BC(void);

void func_800CB114(void *a0) {
    extern void func_80162FF4(s32 a0, s32 a1, s32 a2, s32 a3);
    extern void func_80162FC0(s32 a0);
    extern s32 func_80146E98(s32 a0);
    extern void func_800CB3BC(void);
    extern s32 func_80163950(s32 a0);
    extern s32 func_801638A0(s32 a0, s32 *a1);
    extern void func_80146E90(s32 *a0, s32 a1);
    extern void func_80147324(s32 a0);
    extern void func_80146CA0(void *a0);
    extern void func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
    extern void func_80163328(s32 a0);
    extern s32 func_801632F0(s32 a0);
    extern void func_80162D28(s32 a0);

    s32 vec[2];
    s32 save[2];
    void *obj;
    s32 f;
    s32 w;

    obj = *(void **)((s32)a0 + 0x20);
    memcpy(save, (void *)(obj + 0x10), 8);
    memcpy((void *)(obj + 0x10), (void *)((s32)a0 + 0x58), 8);
    func_80162FF4((s32)a0, 0, 0x20000, 0);
    func_80162FC0((s32)a0);
    *(u16 *)save = *(u16 *)save + 0x71;
    *(u16 *)((s32)save + 4) = *(u16 *)((s32)save + 4) + 0x71;
    memcpy((void *)(obj + 0x10), save, 8);
    if (func_80146E98((s32)a0) != 0) {
        ((void (*)(s32))func_800CB3BC)(a0);
        return;
    }
    f = (func_80163950((s32)a0) != 0) << 13;
    f |= func_801638A0((s32)a0, vec);
    if (f == 0) {
        goto L274;
    }
    if ((f & 0x6000) == 0) {
        goto L250;
    }
    w = *(u16 *)((s32)a0 + 0x60);
    w = w - 1;
    *(u16 *)((s32)a0 + 0x60) = w;
    if ((s16)w == -1) {
        goto L250;
    }
    {
        s32 v = *(s32 *)((s32)a0 + 0x28);
        *(s32 *)((s32)a0 + 0x28) = -(v / 2);
    }
    goto L274;
L250:
    func_80146E90((s32 *)a0, 8);
    func_80147324(0x8E7);
    func_80146CA0(a0);
    return;
L274:
    func_80163408((s32)a0, 0x2A, 0, 0x20);
    func_80163328((s32)a0);
    f = func_801632F0((s32)a0);
    if (f == 2) {
        goto L2E4;
    }
    if ((u32)f < 3) {
        if (f == 1) {
            goto L2CC;
        }
        goto L2E4;
    }
    if (f != 4) {
        goto L2E4;
    }
L2CC:
    func_80146E90((s32 *)a0, 8);
    func_80147324(0x8E7);
    func_80146CA0(a0);
L2E4:
    func_80162D28((s32)a0);
}
