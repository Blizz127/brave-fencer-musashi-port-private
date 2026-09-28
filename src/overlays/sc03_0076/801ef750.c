/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF750 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801EF750(void) {

    extern s16 D_801F96C0;
    extern u16 D_801F96B8;
    extern s32 func_80029504(void);
    extern void func_801EF800(s32, s16);
    s32 v;
    u16 *p;

    v = func_80029504();

    if ((u32)(v - 5) >= 0x4B5) {
        if (v != 0x6A4) {
            D_801F96C0 = 1;
        } else {
            D_801F96C0 = 2;
        }
    } else {
        D_801F96C0 = 0;
    }

    func_801EF800(1, D_801F96C0);
    p = &D_801F96B8;
    (*p)++;
}
