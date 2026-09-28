/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D8B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8013C9C4(void *a0);
extern u16 D_80126B66;

void func_8017D8B0(void *a0) {
    extern u16 D_80126B66;
    extern s32 D_801817E0;

    if (*(s16 *)((char *)a0 + 0xe) > (*(s16 *)&D_80126B66)) {
        *(s32 *)((s32)a0 + 0x1c) = 0x10;
        *(u16 *)((s32)a0 + 0x2) += 1;
        func_8013C9C4(&D_801817E0);
        func_8002D4C8(0x4e8, 0);
    }
}
