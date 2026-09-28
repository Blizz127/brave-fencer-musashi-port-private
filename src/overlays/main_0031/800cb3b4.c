/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_801270C0;
extern u16 D_8011F9D0[];
extern void func_80162CCC(void);

void func_800CB3B4(void) {
    u16 *p;
    s32 i;
    s32 w;

    D_801270C0 = 1;
    i = 0;
    w = 0x17;
    p = D_8011F9D0;
    do {
        if (*p == w) {
            ((void (*)(void *))func_80162CCC)((void *)p);
        }
        i = i + 1;
        p = p + 0x34;
    } while (i < 0x14);
}
