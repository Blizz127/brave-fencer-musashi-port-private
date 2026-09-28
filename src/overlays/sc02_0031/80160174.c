/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160174,801601AC).
 * Offset 0x3801C at overlay base 80128158. SHA256(span)=606a46fe9b41f58f98798fecdfc341297b51af02fd91243288199500c81e07ce.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160174.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160174 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104(void);
extern void func_801601AC(s32 *a0);

void func_80160174(s32 *a0) {
    if (func_80161104()) {
        func_801601AC(a0);
    }
}
