/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80129010 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8011DB2C;
extern s16 D_8011DB30;
extern s32 D_80126AEC;

void func_80129010(void) {
    s32 i;
    s32 s1;
    s32 idx;
    void (*fp)(s32);
    s1 = (s32)&D_8011DB30;
    if (D_8011DB2C == 0) {
        return;
    }
    i = 0;
    do {
        idx = *(u16 *)s1;
        if (idx != 0) {
            fp = (void (*)(s32))(*(s32 *)((idx << 2) + (*(s32 *)&D_80126AEC)));
            fp(s1);
            if (*(s32 *)(s1 + 0x20) != 0) {
                *(s16 *)(*(s32 *)(s1 + 0x20) + 0x8) = *(u16 *)(s1 + 0x6);
                *(s16 *)(*(s32 *)(s1 + 0x20) + 0xA) = *(u16 *)(s1 + 0xA);
                *(s16 *)(*(s32 *)(s1 + 0x20) + 0xC) = *(u16 *)(s1 + 0xE);
            }
        }
        i++;
        s1 += 0x38;
    } while (i < 0x80);
}
