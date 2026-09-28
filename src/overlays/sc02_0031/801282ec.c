/* SC02.CD FILE_031 / ov_SC02_031 retail span [801282EC,8012832C).
 * Offset 0x194 at overlay base 80128158. SHA256(span)=b90b21e852a5798e9d24bff374242c4c9d37adb295664a6844aaf392f4084ad6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801282ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801282EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001C0C8(void);
extern void func_80015310(void);
extern void func_80129258(void);
extern void func_801378F0(void);
extern void func_80010E14(void);

void func_801282EC(void) {
    func_8001C0C8();
    func_80015310();
    func_80129258();
    func_801378F0();
    func_80010E14();
}
