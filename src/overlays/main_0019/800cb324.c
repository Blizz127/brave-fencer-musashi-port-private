/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB324 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB4A8(void);

void func_800CB324(s32 a0) {
    extern void func_8014659C(void);
    extern void func_8001C2C4(s32 a0);
    extern void func_800CB4C8(void *a0);
    extern void func_80146E90(s32 *a0, s32 a1);
    extern void func_80146CA0(void *a0);
    extern void func_800CB4A8(void);

    typedef struct { u32 a, b, c, d; } Blk16;

    s32 iVar1;
    s32 iVar2;
    s32 iVar4;

    iVar2 = *(s32 *)(a0 + 0x4C);
    iVar1 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(a0 + 0x20) = iVar1;
    if (iVar1 != 0) {
        func_8001C2C4(iVar1);
        *(u32 *)(iVar1 + 4) |= 0x80000000;
        iVar4 = *(s32 *)(iVar2 + 0x20);
        *(Blk16 *)(iVar1 + 0x34) = *(Blk16 *)(iVar4 + 0x34);
        *(Blk16 *)(iVar1 + 0x44) = *(Blk16 *)(iVar4 + 0x44);
        func_800CB4C8((void *)a0);
        func_80146E90((s32 *)a0, 0x40);
        func_80146CA0((void *)a0);
    } else {
        ((void (*)(s32))func_800CB4A8)(a0);
    }
}
