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
