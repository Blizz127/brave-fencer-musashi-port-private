/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016D984,8016DA04).
 * Offset 0x4582C at overlay base 80128158. SHA256(span)=3660335be10c1421f43bb7cb0a5770d9c30c015b240feea734876504276a1d70.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016d984.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D984 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146C3C();
extern void func_800D22E4(s32 a0);
extern void func_8012A568(void (*a0)(void));

void func_8016D984(s32 *a0) {
    if ((--*(s32 *)((char *)a0 + 0x1C)) == 0) {
        func_80146C3C();
    } else {
        func_800D22E4((s32)a0);
        *(s32 *)((char *)a0 + 0x10) -= *(s32 *)((char *)a0 + 0x10) >> 4;
        *(s32 *)((char *)a0 + 0x14) -= *(s32 *)((char *)a0 + 0x14) >> 4;
        *(s32 *)((char *)a0 + 0x18) -= *(s32 *)((char *)a0 + 0x18) >> 4;
    }
}
