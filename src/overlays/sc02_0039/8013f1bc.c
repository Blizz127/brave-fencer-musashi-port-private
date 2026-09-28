/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013F1BC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800B9A02;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern u16 D_80115112;
extern void func_800D2624(void);
extern unsigned short D_80115118;
extern unsigned short D_80115114;

void func_8013F1BC(void) {
    unsigned short *p = &D_80115118;
    if (*p != 0) {
        *p -= 0x10;
        __asm__ __volatile__("" ::: "memory");
        if (*p != 0) {
            return;
        }
    }
    if (D_80115114 == ((unsigned short)D_800B9A02 ^ 1)) {
        func_800D2624();
    } else {
        D_80115112 += 1;
    }
}
