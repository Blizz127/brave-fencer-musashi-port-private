/* SC02.CD FILE_031 / ov_SC02_031 retail span [801533A4,80153410).
 * Offset 0x2B24C at overlay base 80128158. SHA256(span)=375a9c7f0aa8ce63bc1ee04954957fa9da0f3b8f90381b05f1ba1bda99eb66e9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801533a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801533A4 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80019064(void *a0);
extern void func_80149020(s32 *a0);
extern s32 func_801472C8(struct S *a0);
extern void func_8014CBF8(void *a0);
extern void func_801474EC(s32 *a0);
extern void func_80155440(s32 *a0);
extern void func_80146CA0(void *a0);
extern u8 D_80062C04[];

void func_801533A4(s32 a0)
{
    func_80019064(D_80062C04);
    func_80149020(a0);
    func_801472C8((struct S *)a0);
    *((u8 *)a0 + 0xDE) = 0x40;
    func_8014CBF8(a0);
    func_801474EC(a0);
    func_80155440(a0);
    func_80146CA0(a0);
}
