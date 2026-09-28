/* Overlay range [8013E5E8,8013E67C) from MAIN.CD member 0012.
 * SHA256(span)=b6eda234ec50440ff8d531ba216025da9b6561ba2848c3561fc82fa3ba99f6d3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E5E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80029444(void);
extern void func_800190AC(void);
extern void func_801754A8(void);
extern unsigned short D_80115112;
extern s32 func_80014ED4(s32);
extern s32 func_80015018(s32);
extern void func_80141C04(void);

void func_8013E5E8(void)
{

    extern u16 D_8011511E;
    extern u16 D_8011511C;
    extern unsigned short D_80115112;
    extern u16 D_80115116;
    extern void (*D_8017F734[])(void);
    register void (*fp)(void) __asm__("$2");  
    func_80029444();
    func_801754A8();
    D_8011511E = func_80014ED4(0);
    D_8011511C = func_80015018(0);
    fp = D_8017F734[D_80115112];
    fp();
    func_800190AC();
    func_80141C04();
    D_80115116 += 1;
}
