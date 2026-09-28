/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FBB8,8016FC24).
 * Offset 0x47A60 at overlay base 80128158. SHA256(span)=be5c64121bcc4a92ac5a850139ecd66048486036d38266c00abb5b185924cd63.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fbb8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FBB8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801719A4(int a0, int a1);
extern void func_80171B44(s32 *a0);
extern s32 func_80171990(u8 *a0);
extern void func_8016FC24();
extern void func_8012A568(void (*a0)(void));

void func_8016FBB8(s32 a0) {
    u8 *p;
    *(s16 *)(a0 + 0x136) = 2;
    p = *(u8 **)(a0 + 0x20);
    *(s16 *)(a0 + 0x132) = *(u16 *)(p + 0x12);
    p = *(u8 **)(a0 + 0x20);
    *(s16 *)(p + 0x12) = (*(u16 *)(p + 0x12) + 0x800) & 0xFFF;
    func_801719A4(a0, 1);
    func_80171B44((s32 *)a0);
    func_80171990((u8 *)a0);
    func_8016FC24(a0);
}
