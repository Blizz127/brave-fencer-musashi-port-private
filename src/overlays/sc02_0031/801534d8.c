/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801534D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern s32 func_80153800(s32 a0);
extern void func_80146D90(s32 a0);
extern void func_80153550(s32 a0);
extern void func_80159B3C(void *a0);
extern void func_80165718(s32 a0);

void func_801534D8(s32 *a0) {
    /* reserved stack local sets frame 0x28 (16-byte local region) */
    volatile s32 pad[4];
    func_80149020(a0);
    if (func_80153800((s32)a0) == 0) {
        *(u16 *)((u8 *)a0 + 0x4) = 0;
        *(u16 *)((u8 *)a0 + 0x8) = 0;
        *(u16 *)((u8 *)a0 + 0xC) = 0;
        *(u16 *)((u8 *)a0 + 0x6) = *(u16 *)((u8 *)a0 + 0x88);
        *(u16 *)((u8 *)a0 + 0xA) = *(u16 *)((u8 *)a0 + 0x8A);
        *(u16 *)((u8 *)a0 + 0xE) = *(u16 *)((u8 *)a0 + 0x8C);
        func_80146D90((s32)a0);
        func_80153550((s32)a0);
        func_80159B3C((s32)a0);
        func_80165718((s32)a0);
    }
}
