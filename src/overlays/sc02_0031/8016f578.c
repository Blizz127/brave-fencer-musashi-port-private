/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F578,8016F5B0).
 * Offset 0x47420 at overlay base 80128158. SHA256(span)=a35f1eb17ddb81ddaf822931224fb1388f7de01c66b8bcae753f160cdd807bc6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f578.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F578 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147084(s32 *a0);
extern void func_801472B4(void *a0);
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016F578(s32 *a0) {
    func_80147084(a0);
    func_801472B4(a0);
    func_80171928(a0);
}
