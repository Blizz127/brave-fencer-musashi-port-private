/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172310,80172358).
 * Offset 0x4A1B8 at overlay base 80128158. SHA256(span)=b181fd5953271535c8fe3d4c60fe7f17fb28a8abbd2f56870cb2b4113abdb70d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172310.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172310 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 D_80126B58;
extern s32 *D_80126B78;
extern void func_80172358(u8 *a0, u8 *a1);

void func_80172310(u8 *a0) {
    func_80172358((u8 *)&D_80126B58, a0);
    *(u16 *)((u8 *)D_80126B78 + 0x12) = *(u16 *)(a0 + 6);
}
