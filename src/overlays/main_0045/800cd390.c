/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD390 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800CE050;
extern void func_8014ACC0(s32, s32);
extern void func_80146CA0(void *a0);
extern void func_80146578(void);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_800CD66C;
extern void func_800CD5BC(void);
extern s32 func_8001CC3C(s32, s32, s32, s32);
extern void func_80149374(s32 a0, s32 a1);
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_8014ACC0(s32 a0, s32 a1);

void func_800CD390(s32 param_1) {
    s32 s0;
    s32 s2;
    u16 temp;
    s2 = *(s32 *)(param_1 + 0x4C);
    s0 = ((s32 (*)(void))func_80146578)();
    *(s32 *)(param_1 + 0x20) = s0;
    if (s0 != 0) {
        ((s32 (*)(s32, void *, s32, s32))func_8001CC3C)(s0, ((u8 *)&D_800CD66C), 0x220, 0x168);
        *(u8 *)(s0 + 0x27) = 0x24;
        *(u8 *)(s0 + 0x24) = 0xFF;
        *(u8 *)(s0 + 0x25) = 0x40;
        *(u8 *)(s0 + 0x26) = 0x40;
        *(u32 *)(s0 + 4) |= 0x50000000;
        func_80149374(s2, param_1 + 4);
        temp = *(u16 *)(*(s32 *)(s2 + 0x20) + 0x10);
        *(s16 *)(s0 + 0x12) = D_800CE050;
        *(u16 *)(s0 + 0x10) = temp;
        *(u16 *)(s0 + 0x14) = *(u16 *)(*(s32 *)(s2 + 0x20) + 0x14);
        *(u16 *)(param_1 + 0x60) = *(u16 *)(s2 + 0x100);
        *(u16 *)(param_1 + 0x62) = *(u16 *)(s2 + 0x102);
        *(u16 *)(param_1 + 0x64) = *(u16 *)(s2 + 0x104);
        *(u16 *)(s0 + 0x1A) = 0x1000;
        *(u16 *)(s0 + 0x18) = 0x1000;
        func_80146DE8((s32 *)param_1, 0, 0, 0xFFE80000);
        func_80146E90((s32 *)param_1, 8);
        func_80146CA0((void *)param_1);
        func_8014ACC0(s2, 1);
    } else {
        ((void (*)(s32))func_800CD5BC)(param_1);
    }
}
