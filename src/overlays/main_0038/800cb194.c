/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB194 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161208();
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_800CB194(s32 *a0) {
    if (func_80161208() == 0) {
        if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
            func_801599A4(a0);
            func_80159B3C(a0);
        }
    }
}
