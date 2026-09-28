/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB0B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB4AC(void);
extern void func_8014659C(void);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);
extern void func_800CB4AC();
typedef struct { s32 w0, w1, w2, w3; } Blk16X;

void func_800CB0B4(s32 param_1) {
    extern void func_8001C214(s32 a0, s32 a1);
    extern s32 D_800CC444;

    s32 iVar2 = *(s32 *)(param_1 + 0x4c);
    s32 obj;

    obj = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(param_1 + 0x20) = obj;
    if (obj != 0) {
        func_8001C214(obj, (s32)&D_800CC444);
        *(u16 *)(obj + 0x10) = *(u16 *)(*(s32 *)(iVar2 + 0x20) + 0x10);
        {
            register s32 prod __asm__("$2");
            prod = (*(s32 *)(param_1 + 0x50) - 1) * 0x155;
            *(u16 *)(obj + 0x12) =
                (*(u16 *)(*(s32 *)(iVar2 + 0x20) + 0x12) + prod) & 0xFFF;
        }
        *(u16 *)(obj + 0x14) = *(u16 *)(*(s32 *)(iVar2 + 0x20) + 0x14);
        *(u16 *)(param_1 + 0x58) = *(u16 *)(iVar2 + 0x100);
        *(u16 *)(param_1 + 0x5A) = *(u16 *)(iVar2 + 0x102);
        *(u16 *)(param_1 + 0x5C) = *(u16 *)(iVar2 + 0x104);
        func_80149374(iVar2, param_1 + 4);
        {
            register s32 dstp __asm__("$3");
            register s32 srcp __asm__("$2");
            dstp = *(volatile s32 *)(param_1 + 0x20);
            srcp = *(volatile s32 *)(iVar2 + 0x20);
            *(Blk16X *)(dstp + 0x34) = *(Blk16X *)(srcp + 0x34);
            *(Blk16X *)(dstp + 0x44) = *(Blk16X *)(srcp + 0x44);
        }
        func_80146DE8(param_1, 0, 0, 0xFFF00000);
        func_800CB4CC((void *)param_1);
        func_80146E90((s32 *)param_1, 0x28);
        func_80147324(0x8E8);
        func_80146CA0((void *)param_1);
    } else {
        ((void (*)(s32))func_800CB4AC)(param_1);
    }
}
