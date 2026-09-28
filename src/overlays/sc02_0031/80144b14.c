/* Complete SC02 retail span [80144B14,80144B9C).
 * Matched C: Druthulu shared ov/func_80144B14.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80144B14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u16 D_80126B5E;
extern u16 D_80126B66;
extern u16 D_80126B62;
extern s32 func_80013294(void *a0, void *a1);

int func_80144B14(int param_s0)
{
    u16 local_buf1[3];
    u16 local_buf2[3];
    s32 call_result;
    local_buf1[0] = *(u16 *)((char *)param_s0 + 0x6);
    local_buf1[1] = *(u16 *)((char *)param_s0 + 0xA);
    local_buf1[2] = *(u16 *)((char *)param_s0 + 0xE);
    local_buf2[0] = D_80126B5E;
    local_buf2[1] = D_80126B62;
    local_buf2[2] = D_80126B66;
    call_result = func_80013294(local_buf1, local_buf2);
    if (call_result < *(s16 *)((char *)param_s0 + 0xFC)) {
        return *(u32 *)((char *)param_s0 + 0xCC);
    }
    return 0;
}
