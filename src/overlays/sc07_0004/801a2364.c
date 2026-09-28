/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2364 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80178B18(s32 a0, s32 a1);
extern void func_801A7D18(s32);
extern void func_801A36F0(void *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_800D0C48(u16 a0);
extern void func_8002A088(s32 a0);
extern void func_8002A2D4(s32 a0);
extern void func_8002A544(s32 a0);
extern void func_8002A7B4(s32 a0);
extern s32 D_801AFD8C;
extern s16 D_801F8868;
extern s32 D_801F8720;

void func_801A2364(s32 a0)
{
    register s32 flag __asm__("$4");

    func_80178B18(a0, (s32)&D_801AFD8C);
    flag = *(s32 *)(a0 + 0xD4);
    *(s32 *)(a0 + 0x1C) = 0x20;
    (*(u16 *)&D_801F8868) = 0;
    if (flag != 0) {
        ((void (*)(void))func_801A7D18)();
        *(s32 *)(a0 + 0xD4) = 0;
        func_801A36F0((void *)a0);
    }
    func_8012AD44((s32 *)a0, 0xF);
    func_800D0C48(1);
    D_801F8720 = 0;
    func_8002A088(0x320);
    func_8002A2D4(0x64);
    func_8002A544(0x190);
    func_8002A7B4(0x12C);
}
