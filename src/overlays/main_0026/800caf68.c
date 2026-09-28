/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF68 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);

void func_800CAF68(void *arg0) {
    extern u8 D_80078E78[];
    extern s32 func_8014C088(s32 a0, s32 a1);
    extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
    extern void func_80147324(s32 arg0);
    extern void func_800CB098(void *a0);
    register u8 *p __asm__("$17") = D_80078E78;

    if (func_8014C088((s32)arg0, 0xB) == 0 || *(u8 *)((s32)arg0 + 0xBE) != 0) {
        func_800CB098(arg0);
    }
    if (*(s32 *)(p + 0x50) == 0) {
        func_801466F0(0xB, (s32)arg0, 0, 0, 0, 1, 0, 0);
        func_80147324(0x7DE);
        *(u8 *)((s32)arg0 + 0xBE) = 0;
        *(u8 *)((s32)arg0 + 0x197) += 1;
    }
}
