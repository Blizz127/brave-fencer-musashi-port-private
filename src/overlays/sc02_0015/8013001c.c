/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013001C - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_8012BCCC(s32 a0);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);

void func_8013001C(void *a0) {
    s32 v0 = func_8012BCCC((s32)a0);
    if (v0 <= 0x8FFF) {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x30)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x31);
    } else {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x31)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x30);
    }
}
