/* SC02.CD FILE_031 / ov_SC02_031 retail span [801746DC,80174714).
 * Offset 0x4C584 at overlay base 80128158. SHA256(span)=9b91c5b371c237dbe94a38de0d4f40f23e4c72e27f8574bd6e26814fbd9459ce.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801746dc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801746DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8016EE94();
extern void func_80174684(void *);
extern void func_80172710(void);
extern s32 func_80172760(s32 a0);

void func_801746DC(void) {
    func_8016EE94((s32)func_80172710, 0x1000000);
    func_80174684((void *)func_80172760);
}
