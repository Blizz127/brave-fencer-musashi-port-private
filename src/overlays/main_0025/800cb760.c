/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB760 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 arg0);

void func_800CB760(void *a0, s16 a1) {
    if (*(s16 *)((s32)a0 + 0x60) != a1) {
        func_80147324((u16)a1);
        *(u16 *)((s32)a0 + 0x60) = a1;
    }
}
