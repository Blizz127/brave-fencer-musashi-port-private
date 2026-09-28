/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB59C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_800B99DA;
extern void func_800CB684(s32 a0, s32 a1);
extern s32 func_80146E98(s32 a0);

void func_800CB59C(s32 a0) {
    s32 ptr;
    s32 v;

    v = D_800B99DA & 1;
    ptr = *(s32 *)((s32)a0 + 0x20);
    if (v == 0) {
        v = 0x160;
    } else {
        v = 0x140;
    }
    *(u16 *)(ptr + 0x2A) = v;
    if (func_80146E98((s32)a0) != 0) {
        func_800CB684((s32)a0, 0x100);
        *(u16 *)((s32)a0 + 2) = 1;
    }
}
