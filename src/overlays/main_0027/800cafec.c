/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFEC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAFEC(s32 *a0) {
    s32 *v1;
    extern s32 func_80161208();
    extern s32 func_80165A20(s32);
    extern void func_801553A8(s32 *a0);
    extern void func_80155440(s32 *a0);
    extern void func_80154150(s32 a0, s32 a1);
    extern void func_80154A74(s32 a0, s32 a1);
    extern void func_80146CA0(void *a0);

    if (func_80161208(a0) != 0) {
        ((void (*)(s32))func_80165A20)((s32)a0);
        return;
    }
    func_801553A8(a0);
    func_80155440(a0);
    func_80154150((s32)a0, 0x26);
    func_80154A74((s32)a0, 0x1E);
    v1 = (s32 *)a0[0x20 / 4];
    *(s16 *)((u8 *)v1 + 0x10) = 0xFE9;
    a0[0x238 / 4] = 0;
    func_80146CA0(a0);
}
