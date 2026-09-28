/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD700 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 f10, f14, f18; } S12_801AD700;
extern s32 func_8012C588(s32 a0, s32 a1);
extern void func_8012B414(s32 a0);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_801AD700(void *a0)
{
    void *s0;
    S12_801AD700 sp10;
    s16 i;

    for (i = 0x100; i < 0x1000; i += 0x200) {
        s0 = (void *)func_8012C588(0x3A1, 0);
        if (s0 != NULL) {
            *(u16 *)((s32)s0 + 0x6) = *(u16 *)((s32)a0 + 0x6);
            *(u16 *)((s32)s0 + 0xA) = *(u16 *)((s32)a0 + 0xA);
            *(u16 *)((s32)s0 + 0xE) = *(u16 *)((s32)a0 + 0xE);
            *(u16 *)(*(s32 *)((s32)s0 + 0x20) + 0x10) = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x10);
            *(u16 *)(*(s32 *)((s32)s0 + 0x20) + 0x12) = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12);
            *(u16 *)(*(s32 *)((s32)s0 + 0x20) + 0x14) = i;
            func_8012B414((s32)s0);
            sp10.f18 = 0;
            sp10.f10 = 0;
            sp10.f14 = 0x400000;
            func_800484EC(*(s32 *)((s32)s0 + 0x20) + 0x34, (s32)&sp10, (s32)s0 + 0x10);
        }
    }
}
