/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F540,8016F578).
 * Offset 0x473E8 at overlay base 80128158. SHA256(span)=7321316120815bef91ac1260ffd2b4385a499cc3fa42396563b71e86f850ba45.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f540.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F540 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S {
    u8  pad0[0x7E]; /* 0x0..0x7D */
    u16 f7E;        /* 0x7E */
};
extern void func_8014708C(void *a0);
extern s32 func_801472C8(struct S *a0);
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016F540(void *a0) {
    func_8014708C(a0);
    func_801472C8((struct S *)a0);
    func_80171928(a0);
}
