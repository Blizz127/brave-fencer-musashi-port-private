/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154358 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8015444C(void *a0, s32 *a1, s32 *a2, s32 *a3);

s32 func_80154358(void * arg0)
{
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 temp_s2;
    u16 temp_s3;
    u16 temp_s1;
    u8 temp_s5;
    u8 temp_s6;
    u8 temp_s7;
    s32 temp_s4;
    s32 ret;
    void *v1;
    temp_s5 = *(u8 *)((u8 *)arg0 + 0xBC);
    temp_s6 = *(u8 *)((u8 *)arg0 + 0xBD);
    temp_s7 = *(u8 *)((u8 *)arg0 + 0xDC);
    sp10 = 0;
    sp14 = 0;
    sp18 = 1;
    temp_s2 = *(s32 *)((u8 *)arg0 + 0xB4);
    temp_s3 = *(u16 *)((u8 *)arg0 + 0xB8);
    temp_s1 = *(u16 *)((u8 *)arg0 + 0xBA);
    temp_s4 = *(s32 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x20);
    func_8015444C(arg0, &sp10, &sp14, &sp18);
    v1 = *(void **)((u8 *)arg0 + 0x20);
    *(s32 *)((u8 *)arg0 + 0xB4) = temp_s2;
    *(u16 *)((u8 *)arg0 + 0xB8) = temp_s3;
    *(u16 *)((u8 *)arg0 + 0xBA) = temp_s1;
    *(u8 *)((u8 *)arg0 + 0xBC) = temp_s5;
    *(u8 *)((u8 *)arg0 + 0xBD) = temp_s6;
    *(u8 *)((u8 *)arg0 + 0xDC) = temp_s7;
    ret = *(s32 *)((u8 *)v1 + 0x20);
    *(s32 *)((u8 *)v1 + 0x20) = temp_s4;
    return ret;
}
