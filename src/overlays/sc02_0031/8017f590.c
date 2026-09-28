/* SC02 resident image [8017F590,8017F5B4) at overlay base 0x80128158.
 * SHA256(span)=7753e8a444b47a05b94115c6a886416750382478181f09aeea48ec6d36bffb7e.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017F590 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8017F5B4(s32 arg0, s32 arg1, s32 arg2);

void func_8017F590(void *a0) {
    s32 a1 = *(s32 *)((u8 *)a0 + 8);
    s32 a2 = (s32)a0 + 0x10;
    func_8017F5B4((s32)a0, a1, a2);
}
