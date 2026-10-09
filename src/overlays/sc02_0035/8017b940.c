/* SC02.CD member35 [8017B940,8017BA3C): twin of main_0012 8017B940 (src/overlays/main_0012/8017b940.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [8017B940,8017BA3C) from MAIN.CD member 0012.
 * SHA256(span)=74c6f1562fe5c4f084976b60dd05452051130ad3d57bfd44b479297d569bf2e2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B940 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;

void func_8017B940(void)
{

    extern u16 D_80126B5E;
    extern u16 D_80126B62;
    extern u16 D_80126B66;
    extern u16 D_801BE8B4;
    extern u16 D_801BE8B6;
    extern u16 D_801BE8B8;
    extern s32 D_80114F30;
    extern s32 D_80114F34;
    extern s32 D_80114F38;
    extern s32 aD80114F24 __asm__("D_80114F24");
    extern s32 D_80114F28;
    extern s32 D_80114F2C;
    extern u8  D_8012694C;
    extern s16 D_801BE834;
    extern short D_801BE8BC;
    extern short D_801BE8BE;
    extern short D_801BE8C0;
    extern s16 D_801BE8AC;
    extern s16 D_801BE8AE;
    extern s16 D_801BE8B0;
    extern s16 D_801BE8A4;
    extern s16 D_801BE8A6;
    extern s16 D_801BE8A8;
    s32 buf[3];

    D_8012694C = 2;
    buf[0] = (*(s16 *)&D_80126B5E) - (*(s16 *)&D_801BE8B4);
    buf[1] = (*(s16 *)&D_80126B62) - (*(s16 *)&D_801BE8B6);
    buf[2] = (*(s16 *)&D_80126B66) - (*(s16 *)&D_801BE8B8);
    (*(s16 *)&D_801BE8BC) = buf[0];
    (*(s16 *)&D_801BE8BE) = buf[1];
    (*(s16 *)&D_801BE8C0) = buf[2];
    D_801BE8AC = D_80114F30 + buf[0];
    D_801BE834 = 0;
    D_801BE8AE = D_80114F34 + buf[1];
    D_801BE8B0 = D_80114F38 + buf[2];
    D_801BE8A4 = aD80114F24 + buf[0];
    D_801BE8A6 = D_80114F28 + buf[1];
    D_801BE8A8 = D_80114F2C + buf[2];
}
