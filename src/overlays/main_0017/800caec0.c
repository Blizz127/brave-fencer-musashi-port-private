/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801657A0(void);
extern s32 func_80165910(s32 a0);
extern void func_801655E4(s32 a0);
extern void func_80147324(s32 a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);

void func_800CAEC0(void *a0) {
    func_801657A0();
    if (func_80165910((s32)a0) == 0) {
        func_801655E4((s32)a0);
    }
    func_80147324(0x47C);
    func_80146994(0x20, (s32)a0, 0x8000, 0);
    *(u8 *)((s32)a0 + 0x197) += 1;
}
