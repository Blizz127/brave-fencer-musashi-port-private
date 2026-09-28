/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80157B74 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int func_80161208();
extern s32 func_80161208();

void func_80157B74(int param_1)
{
    if (*(unsigned short *)(param_1 + 0xB8) == 0x8000) {
        ((void (*)(void))func_801599A4)();
        ((void (*)(int))func_80159B3C)(param_1);
    } else {
        ((void (*)(int))func_80161208)(param_1);
    }
}
