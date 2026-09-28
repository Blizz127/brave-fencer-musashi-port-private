/* SC02.CD FILE_031 / ov_SC02_031 retail span [801722CC,80172304).
 * Offset 0x4A174 at overlay base 80128158. SHA256(span)=2b67ef273bc550d659480cb52ee71d2b15b987111a4a4a2cf067a3992eb454f5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801722cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801722CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80172664(s32 *a0);

void func_801722CC(s32 *a0) {
    if (func_80172664(a0) == 0) {
        *(s16 *)((u8 *)a0 + 0xAC) = 0x40;
        *(s16 *)((u8 *)a0 + 0xAA) = 0x40;
    }
}
