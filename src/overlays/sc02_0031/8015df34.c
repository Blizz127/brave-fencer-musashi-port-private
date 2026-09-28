/* SC02 resident retail span [8015DF34,8015DFE4). Offset 0x35DDC at base 80128158.
 * SHA256(span)=a6a407e1a1e126ea319f2551a040f7d2620227fc2cfce6113a301c3d52fdaac4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DF34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_8018730C[])(void *);
extern int func_8015E0D4(int);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern s32 func_80161208();
extern void func_8015E018(s32 a0);

void func_8015DF34(void *arg0) {
    if (*(u16 *)((u8 *)arg0 + 0xB8) & 0x4000) {
        ((void (*)(void))func_8015E0D4)();
    }
    if (*(u16 *)((u8 *)arg0 + 0xB8) == 0x8000) {
        D_8018730C[*(u16 *)arg0](arg0);
        ((void (*)(void *, s16))func_80147078)(arg0, 0);
        func_80159B70(arg0);
    } else {
        if (*(s32 *)((u8 *)arg0 + 0x178) != 0) {
            ((void (*)(void *))func_8015E018)(arg0);
        }
        ((s32 (*)(void *))func_80161208)(arg0);
    }
}
