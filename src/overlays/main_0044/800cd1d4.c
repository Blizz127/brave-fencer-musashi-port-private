/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD1D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146CA0(void *);
extern s32 func_80146CA0(void *a0);
extern s32 func_80146CA0(void*);
extern void func_80146578(void);
extern void func_8001CC3C(s32, void *, s32, s32);
extern void func_80149374(s32, s32);
extern void func_800CD5EC(void *);
extern void func_800CD834(void *);
extern void func_80146DB8(void *, void *);
extern void func_80146E90(s32*, s32);
extern void func_800CD494(void *);
extern u8 D_800CE1E8[];
extern u8 D_800CE230[];
typedef struct { u16 x, y, z, w; } V8;

void func_800CD1D4(s32 *s1) {
    s32 *s0;
    s32 *s2;
    s32 v0;

    s2 = (s32 *)s1[0x13];
    s0 = (s32 *)((s32 (*)(void))func_80146578)();
    *(s32 *)(s1 + 8) = (s32)s0;
    if (s0 != ((void *)0) ) {
        func_8001CC3C((s32)s0, D_800CE1E8, 0x238, 0x180);
        *(u8 *)((s32)s0 + 0x27) = 0x21;
        *(s32 *)(s0 + 1) |= 0x40000000;
        func_80149374((s32)s2, (s32)(s1 + 1));
        func_800CD5EC(s1);
        v0 = *(s32 *)((s32)s2 + 0x20);
        *(V8 *)((s32)s0 + 0x10) = *(V8 *)((s32)v0 + 0x10);
        *(u16 *)((s32)s1 + 0x60) = *(u16 *)((s32)s2 + 0x100);
        *(u16 *)((s32)s1 + 0x62) = *(u16 *)((s32)s2 + 0x102);
        *(u16 *)((s32)s1 + 0x64) = *(u16 *)((s32)s2 + 0x104);
        func_800CD834(s1);
        func_80146DB8(s1, D_800CE230);
        ((void (*)(void *, s32))func_80146E90)(s1, 0x20);
        *(u16 *)((s32)s1 + 0x5E) = 0;
        func_80146CA0(s1);
    } else {
        func_800CD494(s1);
    }
}
