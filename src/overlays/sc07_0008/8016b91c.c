/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B91C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u8 pad6[0x6];
    u16 h6;
    u16 h8;
    u16 hA;
} SrcB964;
typedef struct {
    u8 pad8[0x8];
    u16 h8;
    u16 hA;
    u16 hC;
} DstB964;
extern void func_8016B964(SrcB964 *a0, DstB964 *a1);
extern void func_8012A568(void (*a0)(void));

void func_8016B91C(s32 arg0) {
    ((void (*)(s32, s32))func_8016B964)(arg0, *(s32*)((u8*)arg0 + 0x10));
    ((void (*)(s32, s32))func_8016B964)(arg0, *(s32*)((u8*)arg0 + 0x14));
    ((void (*)(s32, s32))func_8016B964)(arg0, *(s32*)((u8*)arg0 + 0x18));
}
