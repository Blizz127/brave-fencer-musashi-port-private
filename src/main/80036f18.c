/* Exact retail word export for [80036F18,80036F98); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80036F18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_800C6D28;
extern s32 D_80078F10;
extern s32 D_800A63E8;
extern s32 D_8006AEE8;
extern void func_80034DFC(short);

void func_80036F18(void) {
    s32 i;

    if (D_8006AEE8 != 0) {
        D_800C6D28 = D_800A63E8;
        for (i = 0; i < D_8006AEE8; i++) {
            func_80034DFC(*(short *)(&D_80078F10 + i));
            (&D_80078F10)[i] = 0;
        }
        D_8006AEE8 = 0;
    }
}
