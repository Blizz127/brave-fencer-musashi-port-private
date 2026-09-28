/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168664,80168744).
 * Offset 0x4050C at overlay base 80128158. SHA256(span)=fe3a878b894bafa188d170c720151a21db2d02ec54690ae7c1feaaf4e53dc223.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168664.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168664 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Blk20;
extern Blk20 D_800AE620;
extern s32  func_80049F3C(s32 a0, void *a1);
extern void func_80048EAC(void *a0, void *a1);
extern s32 func_801670E4(s32 a0, s32 a1, s32 a2, s32 a3);

void func_80168664(void *arg0) {
    s32 iVar3;
    void *blk;
    iVar3 = *(s32 *)((u8 *)arg0 + 0x34);
    *(s32 *)((u8 *)arg0 + 0x1c) = 0x20;
    *(s16 *)((u8 *)arg0 + 0x10) = 0x80;
    *(s16 *)((u8 *)arg0 + 0x12) = 0;
    *(s32 *)((u8 *)arg0 + 0x30) = 0x1800;
    *(Blk20 *)((u8 *)arg0 + 0x38) = D_800AE620;
    blk = (u8 *)arg0 + 0x38;
    func_80049F3C(0x400, blk);
    func_80048EAC((void *)(*(s32 *)((u8 *)iVar3 + 0x20) + 0x34), blk);
    func_801670E4((s32)arg0, -6, -0x44, -0x18);
    *(s16 *)((u8 *)arg0 + 2) = *(s16 *)((u8 *)arg0 + 2) + 1;
}
