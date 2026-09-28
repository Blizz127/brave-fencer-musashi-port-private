/* SC02 resident retail span [8013BC7C,8013BCDC). Offset 0x13B24 at base 80128158.
 * SHA256(span)=f2eaee939cb9fa1fdb8de3705dc673f414b53b00ac18236c95197b0116d028e0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E338->D_80184C28.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013BC7C - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char pad_8013BC7C[0x68]; s32 f68; } S_8013BC7C_8013BC7C;

void func_8013BC7C(void *arg0) {

    extern void (*D_80184C28[])(void *);
    D_80184C28[((S_8013BC7C_8013BC7C *)arg0)->f68](arg0);
}
