/* Overlay range [801564B0,801565C0) from MAIN.CD member 0012.
 * SHA256(span)=7f0b616df091759e1971eb40158e3fbe9403fcfe932d59d6d0f1448155796b63.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801564B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 func_8002A1B4(void);
extern s32 func_8002A400(void);
extern s32 func_8002A8E0(void);
extern s32 func_8002A670(void);
extern s32 rand(void);
extern u8 D_80078E78[];

s32 func_801564B0(s32 a0) {
    s32 s0 = (s32)D_80078E78;
    s32 v1;
    if (*(s32 *)(a0 + 0x44) & 0x200) {
        if (rand() & 0x1) {
            return 0x8000;
        }
    }
    if (func_8002A1B4() || func_8002A400() || func_8002A670() || func_8002A8E0()) {
        if ((rand() & 0x3) == 0) {
            return 0x8000;
        }
    }
    if ((rand() & 0x3) != 0) {
        return 0;
    }
    v1 = rand() % 160 & 0xFFFF;
    if ((u32)v1 < 0x51) {
        return 0;
    }
    if (v1 >= *(s16 *)(s0 + 0x2E)) {
         


        __asm__ __volatile__("");
        return 0;
    }
    return 0x8000;
}
