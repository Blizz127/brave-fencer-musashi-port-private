/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801735EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B32;
extern s16 D_80126B40;

void func_801735EC(void *a0) {
    if (D_80126B40 != 0) {
        *(s32 *)((u8 *)a0 + 0x44) |= 0x40000;
    }
    func_801477E8((s32 *)a0, D_80126B32 << 16);
    func_80171A1C((u8 *)a0);
}
