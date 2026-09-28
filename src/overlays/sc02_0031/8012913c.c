/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012913C,801291C0).
 * Offset 0xFE4 at overlay base 80128158. SHA256(span)=92d1323bbc6ef0be1f915da869ea790e724d2de4797721574894ea342b37293b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012913c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012913C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001D074(s32 a, s32 b);
extern u8 *func_801291C0(void);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);

u8 * func_8012913C(s32 arg0)
{
    s32 iVar1;
    u8 *puVar2;
    iVar1 = ((s32(*)(s32,s32))func_8001D074)(0x7E, 0x100);
    if (iVar1 == 0) {
        return (u8 *)0;
    }
    puVar2 = func_801291C0();
    if (puVar2 == (u8 *)0) {
        return (u8 *)0;
    }
    *(s16 *)puVar2 = arg0;
    *(s32 *)(puVar2 + 0x20) = iVar1;
    func_8001CC3C(iVar1, 0, 0, 0);
    return puVar2;
}
