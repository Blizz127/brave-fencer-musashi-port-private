/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172A8C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80171CC4(void *a0, void *a1);
extern void func_80171A1C(u8 *a0);
s32 func_80171CC4(void * a0, void * a1);
extern s16 D_80126B30;

void func_80172A8C(void *a0) {
    if (func_80171CC4(a0, &D_80126B30)) {
        func_80171A1C((u8 *)a0);
    }
}
