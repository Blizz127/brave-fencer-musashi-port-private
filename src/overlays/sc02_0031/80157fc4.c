/* SC02 resident retail span [80157FC4,80158000). Offset 0x2FE6C at base 80128158.
 * SHA256(span)=ad7a9b2234e50ec5f47d089f922988667647d092a1991e7c8968583d41e309e6.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801806D4->D_80186FC4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157FC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186FC4[])(void);

void func_80157FC4(void *a0) {
    D_80186FC4[*(u16 *)((s32)a0 + 0x2)]();
}
