/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB030 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB5A8(void);

void func_800CB030(s32 param_1) {
    extern void func_8014659C(void);
    extern void func_8001CA1C(void *a0, void *a1);
    extern void func_80149374(s32 a0, s32 a1);
    extern void func_80146E90(s32 *a0, s32 a1);
    extern s32 func_80146CA0(void *a0);
    extern void func_800CB5A8(void);
    extern u8 D_800CBFA0[];
    extern s32 D_800CC12C;
    extern void (*D_800CC130[])(void);
    s32 obj;
    s32 p;

    obj = *(s32 *)(param_1 + 0x4C);
    p = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(param_1 + 0x20) = p;

    if (p != 0) {
        func_8001CA1C((void *)p, (void *)((s32)&D_800CBFA0 + *(s32 *)(param_1 + 0x50) * 12));
        *(u32 *)(p + 4) |= 0x08000000;
        func_80149374(obj, param_1 + 4);
        *(u16 *)(param_1 + 0x60) = *(u16 *)(param_1 + 0xA);
        *(u16 *)(param_1 + 0xA) = *(u16 *)(param_1 + 0xA) - 0x200;
        *(s32 *)(param_1 + 0x58) = 0;
        if (*(s32 *)(param_1 + 0x50) == 0) {
            func_80146E90((s32 *)param_1, 0);
            D_800CC130[0] = 0;
        }
        *(u16 *)(param_1 + 0x62) = 0;
        D_800CC12C = 0x384;
        func_80146CA0((void *)param_1);
    } else {
        ((void (*)(s32))func_800CB5A8)(param_1);
    }
}
