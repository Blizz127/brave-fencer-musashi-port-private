/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016B984,8016B9F8).
 * Offset 0x4382C at overlay base 80128158. SHA256(span)=029429cd548923f4dd5875db5df332720c3e28fc1d64903317ac7af088cd3233.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016b984.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B984 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *a0, s32 a1);
extern void func_80146C3C();
extern void func_8012A568(void (*a0)(void));

void func_8016B984(void *a0) {
    if (*(s32*)((s32)a0 + 0x10) != 0) {
        func_80016714(*(void**)((s32)a0 + 0x10), 0x38);
    }
    if (*(s32*)((s32)a0 + 0x14) != 0) {
        func_80016714(*(void**)((s32)a0 + 0x14), 0x38);
    }
    if (*(s32*)((s32)a0 + 0x18) != 0) {
        func_80016714(*(void**)((s32)a0 + 0x18), 0x38);
    }
    ((void (*)(void *))func_80146C3C)(a0);
}
