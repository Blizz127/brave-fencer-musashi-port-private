/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB10C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB10C(void *a0) {
    extern u8 D_80078EC1;
    extern void (*D_800CBCA8[])(void *);
    extern void func_800CB3D0();
    extern void func_800CB3F0();
    extern void func_800CB4AC();

    if (D_80078EC1 != 4) {
        func_800CB3D0(a0);
        return;
    }
    func_800CB3F0(a0);
    func_800CB4AC(a0);
    D_800CBCA8[*(u16 *)((s32)a0 + 0x2)](a0);
}
