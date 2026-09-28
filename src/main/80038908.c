/* Exact retail word export for [80038908,80038958); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80038908 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

void func_80038908(unsigned char *arg0) {
    extern short D_800A4EF8;
    extern unsigned short D_800A4EE0;
    int counter;
    int acc;
    unsigned short *ptr;

    acc = D_800A4EF8 << 7;
    acc *= D_800A4EE0;
    ptr = (unsigned short *)(arg0 + 0x12);
    counter = 0;
    acc >>= 14;
    do {
        acc *= *ptr;
        acc >>= 14;
        counter--;
        ptr += 4;
    } while (counter >= 0);
    *(unsigned short *)(arg0 + 0x10) = (unsigned short)acc;
}
