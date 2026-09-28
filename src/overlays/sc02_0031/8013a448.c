/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013A448,8013A4C4).
 * Offset 0x122F0 at overlay base 80128158. SHA256(span)=5f74c7afe1c4d53d2f201683688ecd7cdbf9dffd4ebdcfef9540329741cd4b02.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013a448.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A448 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013A530();

void func_8013A448(void *a0) {
    s16 *a1 = *(s16 **)((char *)a0 + 0x4);
    if (*(u16 *)((char *)a0 + 0x2) == 0) {
        *(s16 *)((char *)a1 + 0x2A) = 0x400;
        *(s16 *)((char *)a1 + 0x28) = 0x400;
        *(s16 *)((char *)a0 + 0x2) = *(u16 *)((char *)a0 + 0x2) + 1;
    } else {
        *(s16 *)((char *)a1 + 0x28) = *(u16 *)((char *)a1 + 0x28) + 0x200;
        *(s16 *)((char *)a1 + 0x2A) = *(u16 *)((char *)a1 + 0x2A) + 0x200;
        if (*(s16 *)((char *)a1 + 0x28) == 0x1000) {
            *(s16 *)((char *)a0 + 0x0) = 2;
            *(s16 *)((char *)a0 + 0x2) = 0;
        }
    }
    func_8013A530();
}
