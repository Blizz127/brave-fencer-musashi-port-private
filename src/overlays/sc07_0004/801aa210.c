/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA210 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz; } SV_801AA210;
extern void func_80020F34(s32 a0, s32 a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32 a0, s32 a1, void *a2);

void func_801AA210(void *a0, void *a1, void *a2)
{
    SV_801AA210 sv;   /* sp+0x10 */
    u16 arr[3];       /* sp+0x18 */
    s32 flag;         /* sp+0x20 */

    *(s32 *)((s8 *)a1 + 0x14) = *(s16 *)((s8 *)a0 + 0x6);
    *(s32 *)((s8 *)a1 + 0x18) = *(s16 *)((s8 *)a0 + 0xA);
    *(s32 *)((s8 *)a1 + 0x1C) = *(s16 *)((s8 *)a0 + 0xE);

    arr[0] = *(u16 *)(*(s32 *)((s8 *)a0 + 0x20) + 0x18);
    arr[1] = 0x1000;
    arr[2] = *(u16 *)(*(s32 *)((s8 *)a0 + 0x20) + 0x1A);

    func_80020F34((s32)a1, (s32)arr);
    func_8004914C(a1);
    func_800491AC(a1);

    sv.vy = 0;
    sv.vx = 0;
    sv.vz = -0x50;
    func_8004945C((s32)&sv, (s32)a2, &flag);

    sv.vx = -0x38;
    sv.vz = -0x18;
    func_8004945C((s32)&sv, (s32)((s8 *)a2 + 8), &flag);

    sv.vx = 0x38;
    func_8004945C((s32)&sv, (s32)((s8 *)a2 + 0x10), &flag);
}
