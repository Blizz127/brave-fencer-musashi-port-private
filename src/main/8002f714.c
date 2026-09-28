/* Exact retail word export for [8002F714,8002F80C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002F714 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_800760D0;
extern u8 D_800760D4;
extern u8 D_800760D8;
extern u8 D_800760DC;
extern u8 D_8006A96E;
extern void (*D_800A4F24)(void);

extern void func_8002F80C(void);

void func_8002F714(s32 a0, s32 a1) {
    switch (a0 & 0xFFFF) {
        case 0:
            D_800760D0 = a1 & 0x7F;
            D_800A4F24 = func_8002F80C;
            D_8006A96E |= 1;
            break;
        case 1:
            D_800760D4 = a1 & 0x7F;
            D_800A4F24 = func_8002F80C;
            D_8006A96E |= 2;
            break;
        case 2:
            D_800760D8 = a1 & 0x7F;
            D_800A4F24 = func_8002F80C;
            D_8006A96E |= 4;
            break;
        case 3:
            D_800760DC = a1 & 0x7F;
            D_800A4F24 = func_8002F80C;
            D_8006A96E |= 8;
            break;
    }
}
