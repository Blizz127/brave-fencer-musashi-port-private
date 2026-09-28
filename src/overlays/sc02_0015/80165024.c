/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165024 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern s32 func_80146E98(s32 a0);
extern s32  func_80146E98(s32 a0);
extern void func_801651B8(void *a0);

void func_80165024(void *a0) {
    if (func_80146E98((s32)a0)) {
        func_80146CA0(a0);
    }
    func_801651B8(a0);
}
