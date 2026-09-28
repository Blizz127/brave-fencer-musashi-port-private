/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3638 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012BEE8(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_801A43E8(void *a0);
extern void func_801A38E4(void *a0, void *a1, s32 a2, s32 a3, s32 a4);
extern u16 D_801F43C0;

void func_801A3638(void *a0) {
    void *s0 = a0;
    void *s1;
    void *s2;
    u16 flags;

    s1 = *(void **)((u8 *)s0 + 0x64);
    func_8012BEE8((s32)s0);
    s2 = (u8 *)s0 + 0xCC;

    flags = *(u16 *)((u8 *)s0 + 0x5C);
    if (flags & 1) {
        *(u16 *)((u8 *)s0 + 0x5C) = flags & 0xFFFE;
        if (*(s32 *)((u8 *)s0 + 0x1C) == 0
            && *(s32 *)((u8 *)s1 + 0xE8) <= 0xFFFF
            && (*(s32 *)((u8 *)s1 + 0xE0) & 0x140) == 0) {
            func_801A43E8(s0);
            *(u16 *)((u8 *)s1 + 0x2) = 0x15;
            *(s32 *)((u8 *)s1 + 0xE0) = (*(s32 *)((u8 *)s1 + 0xE0) | 1) & ~2;
            *(u16 *)((u8 *)s1 + 0x5C) |= 0x800;
            *(s32 *)((u8 *)s0 + 0x1C) = 0x14;
            func_8002D4C8(4, 0xB79);
            func_8002D4C8(4, 0xB56);
        }
        *(u16 *)((u8 *)s0 + 0x5E) = 0;
    }

    func_801A38E4(s1, s2, D_801F43C0, 5, 1);

    {
        typedef struct { char c[8]; } Blk8;
        void *dst = *(void **)((u8 *)s0 + 0x20);
        void *src = *(void **)((u8 *)s1 + 0x20);

        *(Blk8 *)((u8 *)dst + 0x10) = *(Blk8 *)((u8 *)src + 0x10);
    }

    *(s32 *)((u8 *)s0 + 0x4) = *(s32 *)((u8 *)s1 + 0x4);
    *(s32 *)((u8 *)s0 + 0x8) = *(s32 *)((u8 *)s1 + 0x8);
    *(s32 *)((u8 *)s0 + 0xC) = *(s32 *)((u8 *)s1 + 0xC);
}
