/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB010 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014C088(s32 a0, s32 a1);
extern s32 func_80165A20(s32 a0);
extern void func_800CB108();

void func_800CB010(void *arg0) {
    if (func_8014C088((s32)arg0, 0xB) == 0) {
        *(u8 *)((s32)arg0 + 0x197) += 1;
        func_80165A20((s32)arg0);
    } else if (*(u8 *)((s32)arg0 + 0xBE) != 0) {
        func_800CB108(arg0);
    }
}
