/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB228 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
typedef struct { s32 w0, w1, w2, w3; } Blk16X;
extern s32  func_80146E98(s32 a0);
extern s32  func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C98(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern s32  func_800CB6F4();
extern void func_800CB5CC(void *a0);
extern s32  func_800CB4D4(s32 a0);
extern void func_80013F3C(void *a0);
extern void func_80012558(void *a0, s32 a1);
extern void func_800126C4(void *a0, s32 a1);
extern void func_800123F0(void *a0, s32 a1);
extern void func_80163194(s32 a0, s32 a1, s32 a2, s32 a3, void *a4);
extern void func_80162FC0(s32 a0);
extern s32  func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80163328(s32 a0);
extern s32  func_801632F0(s32 a0);

void func_800CB228(s32 param_1) {
    typedef struct { Blk16X q0; Blk16X q1; s32 pad0, pad1; } Mtx40;
    s32 *obj;
    Mtx40 m;

    obj = *(s32 **)(param_1 + 0x20);
    if (func_800CB6F4(param_1) == 0) {
        func_80146C98((s32 *)param_1, 3);
        return;
    }
    func_800CB5CC((void *)param_1);
    func_80013F3C(&m);
    func_80012558(&m, *(s16 *)(param_1 + 0x5A));
    func_800126C4(&m, *(s16 *)(param_1 + 0x58));
    func_800123F0(&m, *(s16 *)(param_1 + 0x5C));
    func_80012558(&m, *(s16 *)((s8 *)obj + 0x12));
    func_800126C4(&m, *(s16 *)((s8 *)obj + 0x10));
    func_800123F0(&m, *(s16 *)((s8 *)obj + 0x14));
    func_80163194(param_1, 0, 0, -0x3000, &m);
    func_80162FC0(param_1);
    *(Blk16X *)((s8 *)obj + 0x34) = m.q0;
    *(Blk16X *)((s8 *)obj + 0x44) = m.q1;
    if (func_80146E98(param_1) != 0) {
        func_80146E90((s32 *)param_1, 8);
        func_80146CA0((void *)param_1);
        return;
    }
    if (*(s32 *)(param_1 + 0x1C) == 0x27) {
        *(s32 *)(param_1 + 0x54) = func_800CB4D4(param_1);
    }
    func_800CB5CC((void *)param_1);
    func_80163408(param_1, 0x2B, 0, 0x40);
    func_80163328(param_1);
    switch ((u32)func_801632F0(param_1)) {
    case 1:
    case 2:
    case 4:
        func_80146E90((s32 *)param_1, 4);
        obj[1] |= 0x80000000;
        func_80147324(0xA7D);
        func_80146CA0((void *)param_1);
        return;
    }
    if ((*(s32 *)(param_1 + 0x1C) & 1) == 0) {
        func_80146A6C(0x50, (void *)param_1, 0, 0, 0x20, 0, 0);
    }
}
