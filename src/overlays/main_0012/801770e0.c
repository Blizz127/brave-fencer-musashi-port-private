/* Overlay range [801770E0,80177340) from MAIN.CD member 0012.
 * SHA256(span)=35097fec875b4f2bce8bc48a96f009f0a89e39389e25ec9ee6014705f8f81300.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801770E0 - 152 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void *func_80177784(void *a0, s32 a1, s32 a2, s32 a3);
extern u32 func_801783D0(s32 a0, s32 a1);
extern void *func_801777BC();
extern u16 D_8011F830;
extern u16 D_8011F82E;

u32 *func_801770E0(void *param_1, u32 param_2, s16 param_3_)
{
    register s32 c3  __asm__("$21") = 3;     /* $s5 */
    register s32 cb8 __asm__("$20") = 0xb8;  /* $s4 */
    register s32 cff __asm__("$19") = 0xff;  /* $s3 */
    s32 iVar6 = (s16)param_3_;               /* -> $s1 */
    u32 uVar5 = iVar6 << 16;                 /* -> $s0 */
    void *uVar2;
    void *u4, *u5;                           /* fresh single-set save vars (S2 boost) */
    u32 *puVar3;
    s16 sVar1;
    u32 uVar4;
    u32 dl;                                  /* multi-set D-load var (2 sets, no boost) */
    s32 t;
    uVar2 = ((void * (*)(void *, s32, s32))func_80177784)(param_1, uVar5 | (u16)param_2, 0x6e165010);
    uVar2 = ((void * (*)(void *, s32, s32))func_80177784)(uVar2, uVar5 | ((param_2 + 8) & 0xffff), 0x6e165808);
    uVar2 = ((void * (*)(void *, s32, s32))func_80177784)(uVar2, uVar5 | ((param_2 + 0x10) & 0xffff), 0x6e164060);
    u4 = ((void * (*)(void *, s32, s32))func_80177784)(uVar2, uVar5 | ((param_2 + 0x30) & 0xffff), 0x6e163858);
    sVar1 = (s16)func_801783D0(D_8011F830, 4);
    u5 = func_801777BC(u4, sVar1, (s32)((param_2 + 0x18) << 16) >> 16, iVar6, c3, cb8, cff);
    sVar1 = (s16)func_801783D0(D_8011F82E, 4);
    puVar3 = (u32 *)func_801777BC(u5, sVar1, (s32)((param_2 + 0x38) << 16) >> 16, iVar6, c3, cb8, cff);
    dl = ((struct { u16 h; } *)&D_8011F830)->h;
    { u32 v0m = ((u32)(puVar3 - 5) & 0xffffff) | 0x3000000;
      register u32 c6055 __asm__("$6") = 0x6055ff00;
      puVar3[1] = c6055;
      *puVar3 = v0m; }
    uVar4 = ((iVar6 - 4) << 16) | ((param_2 + 1) & 0xffff);
    puVar3[2] = uVar4;
    puVar3[3] = ((s32)(dl * 0x50e6) >> 16) | 0x20000;
    dl = ((struct { u16 h; } *)&D_8011F82E)->h;
    puVar3[5] = ((u32)puVar3 & 0xffffff) | 0x3000000;
    puVar3[10] = ((u32)(puVar3 + 5) & 0xffffff) | 0x3000000;
    puVar3[6] = 0x60ff3214;
    puVar3[7] = uVar4;
    puVar3[0xb] = 0x60000000;
    puVar3[0xc] = ((iVar6 - 5) << 16) | (param_2 & 0xffff);
    t = (s32)(dl * 0x50e6) >> 16;
    puVar3[8] = t | 0x20000;
    puVar3[0xd] = (t + 2) | 0x40000;
    return puVar3 + 0xf;
}
