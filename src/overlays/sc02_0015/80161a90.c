/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161A90 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC0;
extern u8 D_80078E78[];
extern void func_8014AC10();
extern void func_8014AC10(s32 arg0);
extern u8  D_80078EC0;

void func_80161A90(s32 a0)
{
    extern u8 D_80078E78[];
    extern u8 D_80078EC0;
    u8 *p = D_80078E78;
    s32 t;
    if (*(s16 *)(a0 + 0x1C8) == 0) {
        t = 0;
    } else {
        t = ((D_80078EC0 & 0x7F) == 6);
    }
    if (t != 0) {
        __asm__ __volatile__("" ::: "memory");
        *(u16 *)(a0 + 0x1C8) -= 1;
        __asm__("" : "=r"(p) : "0"(p));
    }
    if ((p[0x48] & 0x7F) == 6) {
        if (*(s16 *)(a0 + 0x1C8) == 0) {
            func_8014AC10(0x3B);
        }
    }
}
