/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BE04,8015BE38).
 * Offset 0x33CAC at overlay base 80128158. SHA256(span)=c526bbf9352722ab5e44e43db7088bb126b0ecc25cd2fe82d3684e52dd482c10.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015be04.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
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
