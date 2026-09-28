/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801550FC - byte-exact against retail at -O2 (tools/register_match.py). */
#define MoveImage func_80059A80
typedef struct {
    u8 b[8];
} ImgRect8;
extern void MoveImage(void *a0, s32 a1, s32 a2);
extern void func_800183E0(s32 a0);
extern ImgRect8 D_80180F28[];

void func_801550FC(s32 arg0)
{
    if (arg0 & 0x40000000) {
        MoveImage(&D_80180F28[arg0 & 0xFF], 0x200, 0x100);
    } else {
        ((void (*)(void))func_800183E0)();
    }
}
