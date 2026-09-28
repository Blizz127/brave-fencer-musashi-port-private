/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801621CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800291DC(s32);
extern u8 D_80078E78[];
extern s32 D_80180D80;
extern int func_800291DC(int);
extern u8 D_80078EB0;
extern u8 D_80078EB1;

s32 func_801621CC(s32 arg0) {
    register s32 s0 __asm__("$16") = arg0;        
    register u8 *s1 __asm__("$17") = D_80078E78;  
    register s32 i __asm__("$5");                 
    u32 a2;
    s32 d;                                        
    s32 v, last, hi, lo;
    char pad[8];                                  

    a2 = func_800291DC(8);
    if ((a2 & 0x8000) == 0) {
        return 0;
    }
    a2 &= 0x7FFF;
    if (((a2 >> 8) == D_80078EB1) && ((a2 & 0xFF) <= (u32)D_80078EB0)) {
        return (s32)&D_80180D80;
    }
    d = s1[0x39] - 1;
    i = 0;
    if (s0 <= 0) {
        return 0;
    }
    hi = (a2 >> 8) & 0xFF;
    last = s0 - 1;
    lo = a2 & 0xFF;
    do {
        if ((s8)d < 0) {
            d = 0x17;
        }
        v = (s8)d;
        if (hi == v) {
            if (i != last) {
                return (s32)&D_80180D80;
            }
            i++;
            if ((u32)s1[0x38] < (u32)lo) {
                return (s32)&D_80180D80;
            }
            goto bot;
        }
        i++;
    bot:
        d--;
    } while (i < s0);
    return 0;
}
