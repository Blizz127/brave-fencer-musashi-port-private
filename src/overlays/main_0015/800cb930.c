/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB930 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);
extern s32 func_800CB988(s32 param_1);

void func_800CB930(void *arg0) {
    s32 v;

    v = *(s32 *)((s32)arg0 + 0x1C);
    v++;
    *(s32 *)((s32)arg0 + 0x1C) = v;
    if (v < 2) {
        *(u32 *)((s32)arg0 + 0x30) >>= 1;
        func_800CB988((s32)arg0);
    } else {
        func_80146C3C();
    }
}
