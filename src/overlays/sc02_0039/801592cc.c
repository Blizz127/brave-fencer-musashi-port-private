/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801592CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C98(s32 *a0, s16 a1);
extern void func_80139914(s32 a0);
extern s32 func_8013767C(s32 a0);
extern u8 D_80110C3C[];
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_801399F0(s32 a0);

void func_801592CC(s32 *a0) {
    s32 *s0 = a0;
    s32 *v1 = (s32 *)s0[0x20 / 4];
    *(s16 *)((char *)v1 + 0x12) = (*(u16 *)((char *)v1 + 0x12) + 0x16) & 0xFFF;
    if (func_801399F0(s0[0x198 / 4]) != 0) {
        func_80139914(s0[0x198 / 4]);
        s0[0x198 / 4] = func_8013767C((s32)D_80110C3C);
        func_80146C98(s0, 9);
    }
}
