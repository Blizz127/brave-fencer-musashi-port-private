/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB0B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_8014C050(s32 a0, s32 a1);
extern s32 func_80165A20(s32 a0);

void func_800CB0B8(void *a0) {
    if (func_8014C050((s32)a0, 0x41) == 0) {
        func_80165A20((s32)a0);
        func_801599A4(a0);
        func_80159B3C(a0);
    }
}
