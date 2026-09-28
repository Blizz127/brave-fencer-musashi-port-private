/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB108 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161208();
extern s32 func_80165A20(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);
extern void func_80147324(s32 a0);

void func_800CB108(s32 a0) {
    if (func_80161208()) {
        func_80165A20(a0);
    } else if (*(u16 *)((s32)a0 + 0xB8) == 0x8000) {
        func_80154150(a0, 0x27);
        func_80154A74(a0, 0x1F);
        func_801466F0(0xD, a0, 0, -0x40, 0, 0, 0, 0);
        func_80147324(0x6E2);
        func_80146CA0((void *)a0);
    }
}
