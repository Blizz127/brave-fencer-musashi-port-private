/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160A74,80160ACC).
 * Offset 0x3891C at overlay base 80128158. SHA256(span)=5ee7b200b8c983f99ede61c328f43344aae17c09c6a32499a6fa2bc2a4272fcb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160a74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160A74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80160B00();
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern u8 D_80078EBF;

void func_80160A74(s32 *a0) {
    if (D_80078EBF == 0x80) {
        func_80160B00();
    } else {
        func_80147078(a0, 0);
        func_80159B70(a0);
    }
}
