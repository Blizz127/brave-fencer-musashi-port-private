/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013F138 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801376E8(int a0, int a1);
extern u16 D_80115110;
extern unsigned short D_80115112;
extern unsigned char *func_80141CA4(void);
extern unsigned char D_80180478;
extern u16 D_80115112;
extern unsigned short D_80115118;

void func_8013F138(void) {
    u16 *p = &D_80115118;
    *p += 0x10;
    if ((u16)*p >= 0x40) {
        if (D_80115110 == 0) {
            ((void (*)(int, unsigned char *))func_801376E8)((int)func_80141CA4(), &D_80180478);
        }
        D_80115112 += 1;
    }
}
