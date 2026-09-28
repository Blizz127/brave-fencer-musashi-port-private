/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013A860 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern u8 D_8011DA80[];

void func_8013A860(void) {
    s32 i;
    u8 *p;
    i = 0;
    p = D_8011DA80;
    do {
        func_80016714(p, 0x10);
        i++;
        p += 0x10;
    } while (i < 2);
}
