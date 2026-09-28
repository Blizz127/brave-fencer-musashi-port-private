/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801736B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014C118(void * a0, s32 a1, s32 a2);
extern void func_80174684(void *);
extern s32 func_8014C118(void *a0, s32 a1, s32 a2);
extern s32 func_801736FC();
extern s32 D_80126B58;
extern s32 D_80127508;

void func_801736B0(s32 a0, s32 a1) {
    D_80127508 = func_8014C118(&D_80126B58, a0, (s16)a1);
    func_80174684(func_801736FC);
}
