/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB2A8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern s32 func_80146E98(s32 a0);
extern void func_800CB378(s32 a0);

void func_800CB2A8(s32 a0) {
    s32 v1;
    u16 v0;

    v1 = *(s32 *)(a0 + 0x20);
    v0 = *(u16 *)(v1 + 0x1A);
    v0 = v0 + 0x80;
    *(u16 *)(v1 + 0x1A) = v0;
    *(u16 *)(v1 + 0x18) = v0;
    if (func_80146E98((s32)a0) != 0) {
        func_80146CA0((void *)a0);
    } else {
        func_800CB378(a0);
    }
}
