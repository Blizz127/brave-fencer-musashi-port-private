/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6CA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8013240C(s32 a0);
extern void func_801A4EBC(u8 *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80132784(s32 a0, s32 a1, u32 a2);
extern void func_801A4AAC(void *a0);
extern s32 D_801F8888;
extern s32 D_801F8898;
extern s32 D_801F888C;
extern u16 D_8019FF8A;

void func_801A6CA8(void *arg0) {
    void *s0;
    s32 s1;

    s0 = arg0;
    s1 = *(s32 *)((u8 *)s0 + 0xCC);

    if (*(s16 *)((u8 *)s0 + 0x70) == 0) {
        func_8013240C((s32)&D_801F8888);
        if (s1 != 0) {
            func_8013240C((s32)&D_801F8898);
        }
        func_801A4EBC(s0);
        if (D_801F888C == 1) {
            func_8002D4C8(0xAB9, 0);
            if (*(s16 *)((u8 *)s0 + 0x84) == 0) {
                func_8002D4C8(0xABE, 0);
                *(u16 *)((u8 *)s0 + 0x84) += 1;
            }
        }
    }

    func_80132784((s32)s0, *(s32 *)((u8 *)s0 + 0x64), 0);
    if (D_8019FF8A & 0x100) {
        func_801A4AAC(s0);
    }
}
