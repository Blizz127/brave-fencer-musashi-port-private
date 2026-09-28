/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E3CC - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixYXZ func_80049A1C
extern void RotMatrixYXZ(void *a0, void *a1);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void RotMatrixYXZ(void *a, void *b);
extern void func_800D20C0();

void func_8016E3CC(s32 a0) {
    s16 src[4];
    u8 mtx[8];
    s32 p;
    p = *(s32 *)(a0 + 0x34);
    src[0] = *(u16 *)(p + 0x6);
    src[1] = *(u16 *)(p + 0xA) - 0x28;
    src[2] = *(u16 *)(p + 0xE);
    func_800D20C0((void *)src, (void *)mtx, 6);
    *(s16 *)(a0 + 0x6) = src[0];
    *(s16 *)(a0 + 0xA) = src[1];
    *(s16 *)(a0 + 0xE) = src[2];
    func_800D23D0((void *)mtx);
    RotMatrixYXZ((void *)mtx, (void *)(a0 + 0x38));
}
