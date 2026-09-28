/* SC02 resident retail span [80153CCC,80153D34). Offset 0x2BB74 at base 80128158.
 * SHA256(span)=2c69a74c710f0171cbe31410a50f7cd8195581f643f9a5af88ed67978d3bebbe.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180178->D_80186A68; D_801801A0->D_80186A90.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153CCC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 pad0;
    u16 idx;  /* offset 2 */
} S80153CCC;
extern void func_80019064(void *a0);
extern s32 D_80186A68;
extern void (*D_80186A90[])(void *a0);
extern s16 D_8011DB0C;
extern u16 D_8011F748;

void func_80153CCC(S80153CCC *a0) {
    ((s32 (*)(s32))func_80019064)((s32)&D_80186A68);
    D_80186A90[a0->idx](a0);
    D_8011DB0C = 0;
    D_8011F748 = 0;
}
