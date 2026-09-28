/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB1CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146CA0(void *a0);

void func_800CB1CC(void *arg0) {
    s32 v1 = *(s32 *)((s32)arg0 + 0x20);
    s16 v = *(u16 *)(v1 + 0x1A) + 0x100;
    *(u16 *)(v1 + 0x1A) = v;
    if (v >= 0x1000) {
        *(u16 *)(v1 + 0x1A) = 0x1000;
        func_80146CA0(arg0);
    }
}
