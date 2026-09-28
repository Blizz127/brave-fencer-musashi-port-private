/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BE04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char pad[0x12]; s16 field_0x12; } Obj;
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015BE38();

void func_8015BE04(s32 *a0) {
    func_80147078(a0, 0x3);
    func_8015BE38((struct Obj *)a0);
}
