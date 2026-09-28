/* Complete SC02 retail span [80181938,801819E8); fifth-record state-0 body; C recovery pending */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181938 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80029504(void);
extern void func_8012C1B8(void);
extern void func_8001C2C4(s32 a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern s32 func_8012AD50(void *a0);
extern void func_8012CAE4(void *a0);

void func_80181938(s32 a0) {
    s32 v0;
    s32 v1;
    s32 sp10[3];

    v0 = func_80029504();
    if ((u32)(v0 - 0x82) < 0x334 || v0 >= 0x3E8) {
        func_8012CAE4((void *)a0);
        return;
    }
    v1 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(a0 + 0x20) = v1;
    if (v1 == 0) {
        func_8012CAE4((void *)a0);
        return;
    }
    func_8001C2C4(v1);
    *(s32 *)(a0 + 0x1C) = *(u8 *)(a0 + 0x70);
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) = *(u16 *)(a0 + 0x70) & 0xF00;
    func_8012B2CC(a0);
    sp10[1] = 0;
    sp10[0] = 0;
    sp10[2] = 0x100000;
    func_8012B14C(a0, (s32)sp10);
    func_8012AD50(a0);
}
