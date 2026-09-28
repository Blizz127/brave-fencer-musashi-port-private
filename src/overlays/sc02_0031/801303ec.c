/* SC02.CD FILE_031 / ov_SC02_031 retail span [801303EC,80130438).
 * Offset 0x8294 at overlay base 80128158. SHA256(span)=a59766a8b25e55621734f6362ec7ef1b76f029843e4a21308bc10d7c87f289cf.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801303ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801303EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);

void func_801303EC(void *a0) {
    if (*(s32 *)((u8 *)a0 + 0xB4) & 0x10) {
        func_801319E0((s32)a0);
    }
    func_80131CA8((int)a0, 0xC);
}
