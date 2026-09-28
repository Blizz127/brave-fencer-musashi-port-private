/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB41C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;
extern Blk4_801A7358 *D_801B0358[];
extern Blk4_801A7358 D_801F88F8;
extern u8 D_801F88F9;
extern u8 D_801F88FA;
extern void func_8012AD80(s32 a0);
extern void func_801A7808();
extern s32 func_8012BEE8(s32 a0);
extern void func_8012AD50(void *a0);

void func_801AB41C(void *arg0)
{
    s16 idx;
    s32 flag;
    Blk4_801A7358 *a2;
    u8 *src;
    void *v1;

    idx = *(s16 *)((u8 *)arg0 + 0x70);
    a2 = D_801B0358[idx];
    flag = *(s32 *)((u8 *)arg0 + 0x1C) & 1;
    if (flag != 0) {
        D_801F88F8 = a2[1];
    } else {
        src = (u8 *)a2;
        *(u8 *)&D_801F88F8 = src[4] >> 1;
        D_801F88F9 = src[5] >> 1;
        D_801F88FA = src[6] >> 1;
    }

    func_8012AD80((s32)arg0);
    func_801A7808(arg0, *(void **)((u8 *)arg0 + 0xCC));
    func_801A7808(arg0, *(void **)((u8 *)arg0 + 0xD0));
    func_801A7808(arg0, *(void **)((u8 *)arg0 + 0xD4));

    v1 = *(void **)((u8 *)arg0 + 0xD8);
    if (v1 != NULL) {
        *(u16 *)((u8 *)v1 + 0x6) = *(u16 *)((u8 *)arg0 + 0x6);
        *(u16 *)((u8 *)v1 + 0xA) = *(u16 *)((u8 *)arg0 + 0xA);
        *(u16 *)((u8 *)v1 + 0xE) = *(u16 *)((u8 *)arg0 + 0xE);
    }

    if (func_8012BEE8((s32)arg0) != 0) {
        *(u16 *)((u8 *)arg0 + 0x102) = 0;
        *(u16 *)((u8 *)arg0 + 0x100) = 0;
        *(u16 *)((u8 *)arg0 + 0xFE) = 0;
        *(s32 *)((u8 *)arg0 + 0x1C) = 4;
        func_8012AD50(arg0);
    }
}
