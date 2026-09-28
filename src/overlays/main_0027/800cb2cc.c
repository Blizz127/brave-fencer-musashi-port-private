/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB2CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_800CB7FC();
extern s32 func_8014659C(void);
extern void func_8001C2C4(s32 a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);
extern void func_801466B4(u16 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern u8 D_800CC150[];
extern u8 D_800CC298[];

void func_800CB2CC(s32 arg0) {
    s32 s2;
    s32 s0;
    s32 v;
    u16 h;

    s2 = *(s32 *)(arg0 + 0x4C);
    s0 = func_8014659C();
    *(s32 *)(arg0 + 0x20) = s0;
    if (s0 != 0) {
        func_8001C2C4(s0);
        v = *(s32 *)(s2 + 0x20);
        h = *(u16 *)(v + 0x12);
        *(u16 *)(s0 + 0x1A) = 0;
        *(u16 *)(s0 + 0x18) = 0;
        *(u16 *)(s0 + 0x1C) = 0x1000;
        *(u16 *)(s0 + 0x12) = h;
        func_80146E90((s32 *)arg0, 0x20);
        func_80149374(s2, arg0 + 4);
        *(u32 *)(arg0 + 0x58) = (u32)&D_800CC150[0];
        *(u16 *)(arg0 + 0x60) = 0;
        *(u16 *)(arg0 + 0x62) = 0;
        *(u16 *)(arg0 + 0x64) = 0;
        func_801466B4(0x28, arg0, 0, 0, 1);
        func_801466B4(0x28, arg0, 1, 0, 1);
        memcpy(&D_800CC298[0], (void *)(s2 + 0x154), 8);
        func_80146CA0((void *)arg0);
    } else {
        func_800CB7FC(arg0);
    }
}
