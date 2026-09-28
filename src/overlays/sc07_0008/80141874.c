/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80141874 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801754A8(void);
extern s32 func_80014ED4(s32);
extern s32 func_80015018(s32);
extern void func_80141C04(void);
extern u16 D_8011511E;
extern unsigned short D_80115112;

void func_80141874(void) {

    extern u16 D_8011511C;
    extern u16 D_80115116;
    extern void (*D_8017E700[])(void);
    register void (*fp)(void) __asm__("$2"); /* pin fn-ptr to $v0 → store retires early */
    func_801754A8();
    D_8011511E = func_80014ED4(0);
    D_8011511C = func_80015018(0);
    fp = D_8017E700[D_80115112];
    fp();
    func_80141C04();
    D_80115116 += 1;
}
