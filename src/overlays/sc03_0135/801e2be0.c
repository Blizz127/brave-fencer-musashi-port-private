/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned short D_80115112;

void func_801E2BE0(void)
{
    extern s16 D_800B9A02;
    extern s16 D_801EA954;
    extern s32 D_801151D0;
    extern u8 D_801151C8[];
    extern u32 D_801EAC3C;
    extern u32 D_801EAC40;
    extern u16 D_801EAC44[];
    extern u32 D_801EAC54;
    extern s16 D_80115126;
    extern u16 D_80115112;
    extern u8 D_800B9A15;
    extern s16 D_801EA950;
    s32 pad0;
    s32 var_s0;
    u16 *p;

    (void)&pad0;
    D_801151D0 = *(u32 *)(D_801151C8 + *(u16 *)&D_800B9A02 * 4);
    if (D_801EA954 == 0) {
        D_801EAC54 = func_8002B0B4(D_801EAC3C, D_801EAC40, D_801EAC44);
        if (D_80115126 == 0) {
            func_801E38B4();
        } else {
            func_801E3C1C();
        }
    }
    var_s0 = func_801E2D34();
    func_801E3390();
    if ((var_s0 << 16) != 0) {
        D_801EA950 = var_s0;
        D_800B9A15 = 0;
        p = &D_80115112;
        *p += 1;
    }
}
