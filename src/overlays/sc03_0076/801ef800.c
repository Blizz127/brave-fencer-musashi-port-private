/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF800 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801EF800(s32 a0, s32 a1) {

    extern u8 D_800B9A15;
    extern unsigned char D_800B9A13;
    extern u16 D_80115110;
    extern u16 D_80115112;
    extern s16 D_80115126;
    extern s16 D_801F9ABC;
    extern s16 D_801F9AB8;
    extern void *D_8011DB24;
    extern s32 func_8002D4C8(s32 a0, s32 a1);
    extern void func_801EF878(void);

    void *func_ptr;
    D_800B9A15 = 1;
    D_800B9A13 = 5;
    D_80115110 = 4;
    func_ptr = func_801EF878;
    D_80115112 = 0;
    D_80115126 = (s16)a0;
    D_801F9ABC = (s16)a1;
    D_801F9AB8 = (s16)a1;
    D_8011DB24 = func_ptr;
    return func_8002D4C8(0x1E, 0);
}
