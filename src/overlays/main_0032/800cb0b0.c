/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB0B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB24C(void);
typedef struct { s32 w[4]; } func_800CB0B0_Blk16;
extern void func_8014659C(void);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_800CB0B0(void *arg0) {
    extern u16 D_800CC3C4;
    s32 s0;
    s32 s2;
    s32 flag;
    s32 src;

    s2 = *(s32 *)((s32)arg0 + 0x4C);
    s0 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)((s32)arg0 + 0x20) = s0;
    if (s0 != 0) {
        func_8001C810(s0, (s32)&D_800CC3C4);
        flag = *(s32 *)(s0 + 4);
        flag |= 0x50000000;
        *(s32 *)(s0 + 4) = flag;
        func_80149374(s2, (s32)arg0 + 4);
        src = *(s32 *)(s2 + 0x20);
        *(func_800CB0B0_Blk16 *)(s0 + 0x34) = *(func_800CB0B0_Blk16 *)(src + 0x34);
        *(func_800CB0B0_Blk16 *)(s0 + 0x44) = *(func_800CB0B0_Blk16 *)(src + 0x44);
        func_80146CA0(arg0);
    } else {
        ((void (*)(void *))func_800CB24C)(arg0);
    }
}
