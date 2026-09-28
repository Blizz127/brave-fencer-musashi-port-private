/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A418,8012A464).
 * Offset 0x22C0 at overlay base 80128158. SHA256(span)=e00698062425188e27910bc9f2de60580fb9a39f4d87fd17754cb3760851d55f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a418.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A418 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct BigCopy { s32 words[41]; };
struct Q16 { s32 a, b, c, d; };
extern s32 D_801151D4;
extern struct BigCopy D_80114EE8;

void func_8012A418(void) {
    struct Q16 *src;
    struct Q16 *dst;
    struct Q16 *end;
    src = (struct Q16 *)D_801151D4;
    dst = &D_80114EE8;
    end = src + 10;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (src != end);
    *(s32 *)dst = *(s32 *)src;
}
