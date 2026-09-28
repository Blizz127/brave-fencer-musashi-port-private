/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3A6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32 a0, s32 a1, void *a2);

void func_801A3A6C(u8 *s0)
{
    s16 vec[3];           /* sp+0x10 */
    s32 flag;             /* sp+0x18 */

    func_8004914C((void *)(*(s32 *)(s0 + 0x20) + 0x34));
    func_800491AC((void *)(*(s32 *)(s0 + 0x20) + 0x34));

    vec[1] = 0x40;
    vec[0] = 0;
    vec[2] = -0x30;
    func_8004945C((s32)vec, (s32)vec, &flag);

    *(s16 *)(s0 + 0x6) = *(s32 *)(*(s32 *)(s0 + 0x20) + 0x48) = vec[0];
    *(s16 *)(s0 + 0xA) = *(s32 *)(*(s32 *)(s0 + 0x20) + 0x4C) = vec[1];
    *(s16 *)(s0 + 0xE) = *(s32 *)(*(s32 *)(s0 + 0x20) + 0x50) = vec[2];
}
