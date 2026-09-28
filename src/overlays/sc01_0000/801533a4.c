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
