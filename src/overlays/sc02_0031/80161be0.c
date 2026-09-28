/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161BE0,80161C24).
 * Offset 0x39A88 at overlay base 80128158. SHA256(span)=19923fc5cf85b6eb07dafec6841e87ea12b81cc68f4d5a344d121c7758ad65dd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161be0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_801497A8(void);
extern void func_801599A4(void *a0);
extern void func_80149864(void);

int func_80161BE0(void *param_1)
{
    if (func_801497A8() == 0) {
        return 0;
    }
    func_801599A4(param_1);
    ((void (*)(void *))func_80149864)(param_1);
    return 1;
}
