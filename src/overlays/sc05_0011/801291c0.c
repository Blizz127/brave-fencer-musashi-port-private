/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801291C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *a0, s32 a1);
extern s16 D_8011DB30;

u8 *func_801291C0(void) {
    u8 *p = (u8 *)&D_8011DB30;
    s32 i = 0;
loop:
    if (*(u16 *)p == 0) {
        func_80016714(p, 0x38);
        return p;
    }
    if (++i < 0x80) {
        p += 0x38;
        goto loop;
    }
    return 0;
}
