/* Overlay range [8013F138,8013F1BC) from MAIN.CD member 0012.
 * SHA256(span)=7e9c38c9ed5b5858ec6d12c232df20eda51b6258908c8376b8fcef80fbcd4e9e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013F138 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801376E8(int a0, int a1);
extern u16 D_80115110;
extern unsigned short D_80115112;
extern unsigned char *func_80141CA4(void);
extern u16 D_80115112;

void func_8013F138(void) {

    extern unsigned short D_80115118;
    extern unsigned short D_80115112;
    extern u16 D_80115110;
    extern unsigned char D_8017F6FC;
    u16 *p = &D_80115118;
    *p += 0x10;
    if ((u16)*p >= 0x40) {
        if (D_80115110 == 0) {
            ((void (*)(int, unsigned char *))func_801376E8)((int)func_80141CA4(), &D_8017F6FC);
        }
        D_80115112 += 1;
    }
}
