/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170DE0,80170E34).
 * Offset 0x48C88 at overlay base 80128158. SHA256(span)=ab74292bdafa8beeeef2efe09ba2a9323f6ab34fa3059140d41523afd890e2c0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170de0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170DE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void *D_8011F738;
extern s32 D_8011F73C;
extern s32 D_8011F740;
extern s32 func_80029178(s32 arg);
extern void func_801718AC(void *a0);

void func_80170DE0(u8 * _arg0)
{
    s32 arg;
    if (((u8 (*)(s32))func_80029178)(D_8011F738)) {
        arg = D_8011F740;
    } else {
        arg = D_8011F73C;
    }
    ((void (*)(s32))func_801718AC)(arg);
}
