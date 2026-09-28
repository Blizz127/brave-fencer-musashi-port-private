/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCD50 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_80147324(s32 a0);

void func_800CCD50(void) {
    register void *a0 __asm__("$4");
    extern void func_80154274(s32 *a0, s32 a1);
    extern void func_80146D90(s32 a0);
    extern void func_800CCDB0(s32 *a0);
    extern M2C_UNK D_800CE010;
    s32 s0;
    s32 v0;
    u16 v1;

    s0 = (s32)a0;
    func_80154274((s32 *)s0, (s32)&D_800CE010);
    v0 = *(s32 *)(s0 + 0x20);
    v1 = *(u16 *)(v0 + 0x12);
    *(u16 *)(s0 + 0x246) = 0x200;
    *(u16 *)(s0 + 0x244) = v1;
    func_80146D90(s0);
    func_800CCDB0((s32 *)s0);
    *(u16 *)(s0 + 0x240) = 0;
    func_80147324(0x8E4);
}
