/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801663A4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32, void*, s32, s32, s32, s32, s32);

void func_801663A4(void *a0) {
    func_80146A6C(3, a0, *(s16 *)((s32)a0 + 6),
                  (s16)(*(u16 *)((s32)a0 + 0xA) - 0x10),
                  *(s16 *)((s32)a0 + 0xE), 0xCCCFFF8, 0xE000C000);
}
