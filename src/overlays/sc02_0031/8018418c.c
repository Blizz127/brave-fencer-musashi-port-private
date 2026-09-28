/* Complete SC02 retail span [8018418C,80184318).
 * Live STOP 84238 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8018418C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_8018942C;
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8005C49C(void);

void func_8018418C(int param_1)
{
    s32 ptr;
    s32 r;

    func_8001CB6C((u8 *)*(s32 *)(param_1 + 0x20), &D_8018942C, 0x234, 0x1C0);
    *(u8 *)(*(s32 *)(param_1 + 0x20) + 0x27) = 0x26;
    *(s16 *)(param_1 + 0x30) = func_8005C49C() & 0x1FF;
    *(s16 *)(param_1 + 0x32) = func_8005C49C() & 0x1F;
    *(s16 *)(param_1 + 0x34) = func_8005C49C() & 0x7F;
    r = func_8005C49C();
    ptr = *(s32 *)(param_1 + 0x20);
    *(s16 *)(ptr + 0x1A) = (r % 0x1000) + 0x800;
    *(s16 *)(ptr + 0x18) = *(s16 *)(ptr + 0x1A);
    *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
}
