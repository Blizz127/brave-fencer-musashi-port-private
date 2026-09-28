/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801775E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_8011F83B;
extern u8 D_8011F837;
extern u8 D_8011F7F0;
extern void func_801776EC(u8 *a0);

void func_801775E0(s32 param_1, s32 param_2) {
    s32 s0 = param_1;
    s32 pp = param_2;
    u8 *base = &D_8011F7F0;
    s16 sVar1; s32 t; s32 v;
    s32 c = D_8011F83B;
    if (c != 0) {
        if (c < 0) goto store;
        if (c >= 0xf7) goto store;
        if (c < 0xf3) goto store;
        goto docall;
    }
    if (D_8011F837 != 0x80) {
        *(u8 *)(s0 + 4) = 0xff;
        *(u8 *)(s0 + 6) = 0x10;
        *(u8 *)(s0 + 5) = 0x10;
        goto L684;
    }
    func_801776EC((u8 *)s0);
    goto L684;
docall:
    func_801776EC((u8 *)s0);
    goto L684;
store:
    *(u8 *)(s0 + 5) = 0xff;
    *(u8 *)(s0 + 6) = 0x10;
    *(u8 *)(s0 + 4) = 0x10;
L684:
    sVar1 = (s16)((u32)(base[0x47] * 9) >> 4);
    t = pp + 0x48;
    *(s16 *)(s0 + 0xe) = sVar1;
    *(s16 *)(s0 + 0xa) = t - sVar1;
    if (base[0x47] != 0) { s0 = param_1 + 0x14; v = 0xa0; } else { s0 = param_1 + 0x14; v = 0x40; }
    *(u8 *)(s0 + 6) = v;
    *(s16 *)(s0 + 0xa) = pp;
}
