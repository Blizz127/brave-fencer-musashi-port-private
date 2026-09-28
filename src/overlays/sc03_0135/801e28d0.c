/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E28D0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern void func_801E2980(s32 arg0, s32 arg1);

void func_801E28D0(void) {

    extern s16 D_801EA55C;
    extern unsigned short D_801EA554;
    s32 v;
    unsigned short *p;

    v = func_80029504();
    if ((u32)(v - 5) >= 0x4B5) {
        if (v != 0x6A4) {
            D_801EA55C = 1;
        } else {
            D_801EA55C = 2;
        }
    } else {
        D_801EA55C = 0;
    }
    func_801E2980(1, D_801EA55C);
    p = &D_801EA554;
    *p = *p + 1;
}
