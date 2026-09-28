/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142B2C,80142BB4).
 * Offset 0x1A9D4 at overlay base 80128158. SHA256(span)=74d72a4f868d863d11aa99338bc120122c0064497a212869ef83d030582c45cb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142b2c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142B2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80142C84(s32 a0);
extern void func_80143994(s32 a0, s32 a1);
extern s32 func_8012AD50(void *a0);

void func_80142B2C(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x1c) = 0x180;
    *(s16 *)((u8 *)arg0 + 0x5c) = 0x100;
    *(u16 *)((u8 *)arg0 + 0x100) = *(u16 *)((u8 *)arg0 + 0x70) & 0x100;
    *(u16 *)((u8 *)arg0 + 0x70) = *(u16 *)((u8 *)arg0 + 0x70) & 3;
    *(u16 *)((u8 *)arg0 + 0x72) = *(u16 *)((u8 *)arg0 + 0x72) | 0x1000;
    if (*(s16 *)((u8 *)arg0 + 0x100) == 0) {
        ((void (*)(void))func_80142C84)();
    }
    *(s32 *)((u8 *)arg0 + 0xcc) =
        ((s32 (*)(s32, s32))func_80143994)(
            (s32)arg0, (s32)*(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x18));
    func_8012AD50(arg0);
}
