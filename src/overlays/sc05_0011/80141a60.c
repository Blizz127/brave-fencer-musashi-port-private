/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80141A60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern volatile u16 D_8011511A;
extern s16 D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern s16 D_8011514C;
extern s32 D_80115130;
extern u8  D_8017F094;
extern u16 D_80115112;
extern s32  func_8013F350(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern s32  func_8014032C(s32 a0, s32 a1);
extern void func_80139954(void);
extern void func_801376E8(int a0, int a1);
extern void func_80137B80(void);
extern s32  func_800D0EC4(void);

void func_80141A60(void)
{

    extern u8  D_8011514D;
    extern u8  D_8011515C;
    extern u16 D_80115116;
    s32 iVar1;
    s32 pad[2];
    (void)&pad;   /* §36#3 frame-pad induction: force frame 0x20 (vs 0x18) */

    D_801151D0 = ((s32 *)D_801151C8)[(*(u16 *)&D_800B9A02)];
    func_8013F350();
    if ((*(u16 *)&D_8011511A) >= 4) {
        func_8013FAF8((*(u16 *)&D_8011511A), (*(u16 *)&D_8011511A) + 1);
    }
    func_8013FAF8(2, 3);
    iVar1 = func_8014032C(2, (s16)((*(u8 *)&D_8011514C) + D_8011514D * D_8011515C));
    if (iVar1 != 0 && iVar1 != D_80115130) {
        D_80115130 = iVar1;
        func_80139954();
        func_801376E8(iVar1, (int)&D_8017F094);
    }
    func_80137B80();
    iVar1 = func_800D0EC4();
    if (iVar1 != 0) {
        D_80115116 = 0xfff8;
        D_80115112 = D_80115112 + 1;
    }
}
