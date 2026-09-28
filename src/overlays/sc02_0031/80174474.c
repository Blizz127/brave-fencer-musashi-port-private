/* SC02 resident retail span [80174474,801744B0). Offset 0x4C31C at base 80128158.
 * SHA256(span)=6465f8a77d2dc2b86d70843e3b8c0479aeb8bbf101050f5cfdaaaf522910a798.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819D8->D_801882C8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174474 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80174474(void *a0) {

    extern void (*D_801882C8[])(void);
    D_801882C8[*(u8 *)((s32)a0 + 0x214)]();
}
