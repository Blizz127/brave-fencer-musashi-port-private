/* SC02.CD member35 [801588CC,80158AB4): twin of main_0012 801588CC (src/overlays/main_0012/801588cc.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, rodata 0x801BCEB4, B28 inc 107 twin port). */
/* Overlay range [801588CC,80158AB4) from MAIN.CD member 0012.
 * SHA256(span)=fa82cbd335aace6d4a6cbd8b77eb972dc7dbd0da30c44805c9cf1d78ebe7f545.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801588CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define SsGetMute func_8001BD80

void func_801588CC(int param_1) {

    extern void (*D_80186870[])(int);
    extern s32 D_801BD770;
    extern s32 D_801BD774;
    extern s32 D_801BD778;
    extern s32 D_801BD77C;
    extern s32 D_801BD780;
    extern int func_800D0CA0(int);
    extern int func_8001AAA0(int);
    extern int SsGetMute(void);
    extern s32 func_80159464(void);
    short sVar1;

    D_80186870[*(unsigned short *)(param_1 + 2)](param_1);
    switch (D_801BD770) {
    case 0:
        break;
    case 1:
        func_800D0CA0(2);
        D_801BD778 = 0;
        D_801BD774 = 0x46;
        D_801BD770 += 1;
        break;
    case 2:
        if (D_801BD774 == 0) {
            if (SsGetMute() == 0) {
                D_801BD770 += 1;
            }
        } else {
            D_801BD774 -= 1;
        }
        break;
    case 3:
        if (func_8001AAA0(0x83) != 0) {
            D_801BD770 += 1;
        }
        break;
    case 4:
        D_801BD77C = 0;
        sVar1 = ((int (*)(int))func_80159464)(param_1);
        if (sVar1 != 0) {
            D_801BD774 = 0xd2;
        } else {
            D_801BD774 = 1;
        }
        break;
    case 5:
        D_801BD774 -= 1;
        if (D_801BD774 == -1 || D_801BD780 != 0) {
            D_801BD774 = 0;
            D_801BD770 += 1;
        }
        break;
    case 6:
        func_800D0CA0(1);
        D_801BD774 = 0x28;
        D_801BD770 += 1;
        break;
    case 7:
        if (D_801BD774 == 0) {
            if (SsGetMute() == 0) {
                D_801BD770 += 1;
            }
        } else {
            D_801BD774 -= 1;
        }
        break;
    case 8:
        D_801BD778 = 1;
        break;
    }
}
