/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2980 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E2980(s32 arg0, s32 arg1)
{
    extern u8 D_800B9A15;
    extern u8 D_800B9A13;
    extern u16 D_80115110;
    extern s16 D_80115126;
    extern s16 D_801EA958;
    extern s16 D_801EA954;
    extern unsigned short D_80115112;
    extern void *D_8011DB24;
    extern void func_801E29F8(void);
    extern s32 func_8002D4C8(s32, s32);

    D_800B9A15 = 1;
    D_800B9A13 = 5;
    D_80115110 = 4;
    D_80115126 = arg0;
    D_801EA958 = arg1;
    D_801EA954 = arg1;
    D_80115112 = 0;
    D_8011DB24 = func_801E29F8;
    func_8002D4C8(0x1E, 0);
}
