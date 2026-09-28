/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013F244 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_8011511A;
extern u16 D_8011511E;
extern void func_80141C0C(s32);

void func_8013F244(void)
{
    u16 *p = &D_8011511A;
    u16 uVar1;
    s32 iVar2;
    iVar2 = 0;
    if (*p < 3) {
        if ((D_8011511E & 0x2000) != 0) {
            uVar1 = *p + 1;
            iVar2 = 1;
            *p = *p + 1;
            if (2 < uVar1) {
                *p = 0;
            }
        }
        if ((D_8011511E & 0x8000) != 0) {
            D_8011511A = D_8011511A - 1;
            if (2 < D_8011511A) {
                D_8011511A = 2;
            }
            iVar2 = iVar2 + 1;
        }
        if ((D_8011511E & 0x5000) != 0) {
            D_8011511A = 3;
            iVar2 = iVar2 + 1;
        }
    } else {
        iVar2 = 0;
        if ((D_8011511E & 0x5000) == 0)
            goto done;
        *p = 0;
        iVar2 = 1;
    }
done:
    if ((iVar2 << 0x10) != 0) {
        func_80141C0C(2);
    }
    return;
}
