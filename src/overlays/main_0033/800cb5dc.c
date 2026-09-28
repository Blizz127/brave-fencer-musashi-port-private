/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB5DC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);
extern void func_801465C0(void);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *a0, u16 a1);

void func_800CB5DC(void *arg0) {

    extern u8 D_800CBA88;
    extern u8 D_800CBA89;
    extern u8 D_800CBA8A;
    extern u8 D_800CBA8C;
    extern u8 D_800CBA8D;
    extern u8 D_800CBA8E;
    void *s3;
    void *s1;
    void *s0;
    u16 v1;

    s3 = *(void **)((u8 *)arg0 + 0x34);
    s1 = ((void *(*)(void))func_801465C0)();
    *(void **)((u8 *)arg0 + 0x20) = s1;

    if (s1 != ((void *)0) ) {
        s0 = &D_800CBA88;
        func_8001CD50((s32)s1, (s32)s0);
        func_800233CC(s0, 0x20);

        *(u8 *)s0 = 0x20;
        D_800CBA89 = 0x40;
        D_800CBA8A = 0x80;
        D_800CBA8E = 0;
        D_800CBA8D = 0;
        D_800CBA8C = 0;

        *(s32 *)((u8 *)s1 + 4) |= 0x50000000;

        v1 = *(u16 *)(*(void **)((u8 *)s3 + 0x20) + 0x12);
        *(s16 *)((u8 *)s1 + 0x10) = 0x400;
        *(s32 *)((u8 *)s1 + 0x34) = (s32)((u8 *)arg0 + 0x38);
        *(s16 *)((u8 *)s1 + 0x12) = v1;

        *(u16 *)((u8 *)arg0 + 2) = *(u16 *)((u8 *)arg0 + 2) + 1;
    } else {
        ((void (*)(void *))func_80146C3C)(arg0);
    }
}
