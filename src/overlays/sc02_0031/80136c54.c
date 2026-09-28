/* SC02 resident retail span [80136C54,80136C90). Offset 0xEAFC at base 80128158.
 * SHA256(span)=7c552b666cd83711941c299478b06e67e7db319fb005685c5f83573f77205728.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E92C->D_8018521C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80136C54 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern unsigned short D_800B99F0;
extern void (*D_8018521C[])(void);

void func_80136C54(void)
{
    D_8018521C[D_800B99F0]();
}
