/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015AD78,8015ADB0).
 * Offset 0x32C20 at overlay base 80128158. SHA256(span)=8d09596bbdb49fd6e9096da5c756ce443ce87842f0e3402dbcff9096b5a4df3f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015ad78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015AD78 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104(void);
extern void func_8015ADB0(s32);

void func_8015AD78(s32 a0) {
    if (func_80161104() != 0) {
        func_8015ADB0(a0);
    }
}
