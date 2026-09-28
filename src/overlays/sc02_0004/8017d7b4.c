/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D7B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016F0E4(void);
extern void func_800D1724(s32 a0);
extern s32 D_801816EC;

void func_8017D7B4(a0)
void *a0;
{
    extern s32 D_801816EC;
    extern void func_8016F0E4(void);
    s32 v0 = *(s32 *)((u8 *)a0 + 0x204) - 1;
    *(s32 *)((u8 *)a0 + 0x204) = v0;
    if (v0 == -1) {
        func_800D1724((s32)&D_801816EC);
        ((void (*)(void *))func_8016F0E4)(a0);
    }
}
