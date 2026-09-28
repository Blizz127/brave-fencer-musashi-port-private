/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCD2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800CE050;
extern void func_800CCE60();
extern void func_8014659C(void);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_800CCE80(void*);
extern void func_80146CA0(void *a0);
extern s32 D_800CE048;

void func_800CCD2C(s32 s1) {
    s32 s2;
    s32 s0;

    s2 = *(s32 *)(s1 + 0x4C);
    s0 = ((s32 (*)())func_8014659C)();
    *(s32 *)(s1 + 0x20) = s0;
    if (s0 != 0) {
        func_8001C810(s0, &D_800CE048);
        *(u32 *)(s0 + 4) |= 0x50020000;
        *(u16 *)(s0 + 0x1C) = 0;
        *(u16 *)(s0 + 0x1A) = 0;
        *(u16 *)(s0 + 0x18) = 0;
        ((void (*)(s32))func_800CCE80)(s1);
        D_800CE050 = *(u16 *)(*(s32 *)(s2 + 0x20) + 0x12);
        func_80146CA0((void *)s1);
    } else {
        ((void (*)(s32))func_800CCE60)(s1);
    }
}
