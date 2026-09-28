/* SC02.CD FILE_031 / ov_SC02_031 retail span [801724EC,8017250C).
 * Offset 0x4A394 at overlay base 80128158. SHA256(span)=d7a64ba9faeb4ce0944d0d9786bcaadb7fedc85d36e8995e9d410aa004f6be85.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801724ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801724EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80013450(s32);

s32 func_801724EC(s32 a0) {
    return func_80013450(a0 + 4) < 0x10;
}
