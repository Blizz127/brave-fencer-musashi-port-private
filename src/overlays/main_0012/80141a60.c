/* Overlay range [80141A60,80141B90) from MAIN.CD member 0012.
 * SHA256(span)=c27ce34d8bf0f56290ccf632162e611417b2457f9e13dc8fd80d85d919dcb651.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80141A60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
extern u8 D_8011514D;

extern s32 func_800D0EC4(void);
extern void func_801376E8(int a0, int a1);
extern void func_80137B80(void);
extern void func_80139954(void);
extern s32 func_8013F350(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern s32 func_8014032C(s32 a0, s32 a1);

// @class: plumbing
// @stuck: TBD — first pass



s32 func_80141A60()
{

    extern short D_800B9A02;
    extern unsigned short D_80115112;
    extern u16 D_80115116;
    extern u16 D_8011511A;
    extern s32 D_80115130;
    extern s16 D_8011514C;
    extern u8 D_8011515C;
    extern u8 D_801151C8[];
    extern s32 D_801151D0;
    extern unsigned char D_8017F6FC;
    int v;
    s32 frame_pad[2];
    (void)&frame_pad;

    D_801151D0 = ((int *)D_801151C8)[(*(unsigned short *)&D_800B9A02)];
    func_8013F350();
    if ((*(unsigned short *)&D_8011511A) >= 4) {
        func_8013FAF8((short)(*(unsigned short *)&D_8011511A), (short)((*(unsigned short *)&D_8011511A) + 1));
    }
    func_8013FAF8(2, 3);
    v = ((int(*)(int, int))func_8014032C)(2, (short)((*(unsigned char *)&D_8011514C) + (*(unsigned char *)&D_8011514D) * (*(unsigned char *)&D_8011515C)));
    if (v != 0 && v != D_80115130) {
        D_80115130 = v;
        func_80139954();
        ((void (*)(int, void *))func_801376E8)(v, &(*(int *)&D_8017F6FC));
    }
    func_80137B80();
    if (func_800D0EC4() != 0) {
        (*(unsigned short *)&D_80115116) = 0xFFF8;
        (*(unsigned short *)&D_80115112) = (*(unsigned short *)&D_80115112) + 1;
    }
}
