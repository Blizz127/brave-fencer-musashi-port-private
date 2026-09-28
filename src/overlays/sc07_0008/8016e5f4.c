/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E5F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012EFB8(s32 a0);
extern void func_80146C3C();
extern void func_80015954(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));

void func_8016E5F4(s32 arg0) {
    s32 sp10;
    func_80015978(arg0 + 4, &sp10);
    if ((((s32 (*)(s32, s32))func_8012EFB8)((s32)&sp10, (s32)&sp10) & 0xFFFFEFFF) != 0) {
        ((void (*)(s32))func_80146C3C)(arg0);
    } else {
        func_80015954((s32)&sp10, arg0 + 4);
        *(s16 *)((u8 *)arg0 + 0x10) = 0x100;
        *(s16 *)((u8 *)arg0 + 0x12) = 0;
        *(s16 *)((u8 *)arg0 + 0x14) = 0;
        *(s16 *)((u8 *)arg0 + 0x16) = 0x80;
        *(s16 *)((u8 *)arg0 + 2) = *(u16 *)((u8 *)arg0 + 2) + 1;
    }
}
