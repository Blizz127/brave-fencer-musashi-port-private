/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80155B9C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80147460(s32 a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern s32 D_800D4DB4;

void func_80155B9C(s32 a0) {
    *(s32 *)(a0 + 0x44) |= 2;
    func_80148038(a0, 0x30000);
    func_80147460(a0);
    if (*(s32 *)(a0 + 0x34) >= 0) {
        func_80154274((s32 *)a0, (s32)&D_800D4DB4);
        func_80146CA0((void *)a0);
        func_80147324(0x447);
    }
}
