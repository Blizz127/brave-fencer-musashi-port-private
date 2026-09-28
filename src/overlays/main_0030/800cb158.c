/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB158 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB158(void *a0) {

    extern u8 D_80078EC1;
    extern void (*D_800CB51C[])(void);
    extern u8 D_800CB51D;
    extern u8 D_800CB51E;
    extern void func_800233CC(void *, u16);
    extern void func_80146C3C(void *);

    if (D_80078EC1 == 0x13) {
        if (*(s32 *)((s32)a0 + 0x1c) < 0x10) {
            u8 v = D_800CB51E + 8;
            D_800CB51E = v;
            D_800CB51D = v;
            *(u8 *)D_800CB51C = v;
            func_800233CC((void *)D_800CB51C, 0x24);
        }
        *(s32 *)((s32)a0 + 0x1c) = *(s32 *)((s32)a0 + 0x1c) + 1;
    } else {
        func_80146C3C(a0);
    }
}
