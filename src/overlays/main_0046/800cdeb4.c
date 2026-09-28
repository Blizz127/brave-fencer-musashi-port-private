/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDEB4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern s32 func_80146E98(s32 a0);
extern void func_800CDF84(s32, s32);
extern void func_80163194(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_80162FC0(void *a0);
extern s32 func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80163328(void *a0);
extern s32 func_801632F0(void *a0);

void func_800CDEB4(void *arg0) {
    s32 *s1;
    u16 var;
    s32 sp18[8];

    s1 = *(s32 **)((u8 *)arg0 + 0x20);
    if (func_80146E98((s32)arg0) != 0) {
        func_80146CA0(arg0);
    } else {
        ((void (*)(void *, void *))func_800CDF84)(arg0, sp18);
        func_80163194((s32)arg0, 0, 0, 0, (s32)sp18);
        func_80162FC0(arg0);
        var = *(u16 *)((u8 *)s1 + 0x1A) + 0x100;
        *(u16 *)((u8 *)s1 + 0x1A) = var;
        *(u16 *)((u8 *)s1 + 0x18) = var;
        func_80163408((s32)arg0, 0x23, 0x80, 8);
        func_80163328(arg0);
        func_801632F0(arg0);
    }
}
