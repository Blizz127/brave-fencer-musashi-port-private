/* Overlay range [80141874,801418F8) from MAIN.CD member 0012.
 * SHA256(span)=dae6e3948f9507f327da044197738a6642117e6b769c79bc452567849dc61206.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80141874 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801754A8(void);
extern unsigned short D_80115112;
extern s32 func_80014ED4(s32);
extern s32 func_80015018(s32);
extern void func_80141C04(void);
extern u16 D_8011511E;
extern u16 D_80115112;
extern u16 D_8011511C;

void func_80141874(void) {

    extern u16 D_8011511E;
    extern u16 D_8011511C;
    extern unsigned short D_80115112;
    extern u16 D_80115116;
    extern void (*D_8017F780[])(void);
    register void (*fp)(void) __asm__("$2");  
    func_801754A8();
    D_8011511E = func_80014ED4(0);
    D_8011511C = func_80015018(0);
    fp = D_8017F780[D_80115112];
    fp();
    func_80141C04();
    D_80115116 += 1;
}
