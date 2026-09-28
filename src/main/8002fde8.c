/* Exact retail word export for [8002FDE8,8002FF0C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002FDE8 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_800A469C;
extern s16 D_800A46A0;
extern s16 D_800A46A2;
extern u8  D_800A46B0;
extern s32 D_800652F0[];

extern void func_8002ED90(void);
extern void func_800415A8(s32);
extern s16  func_80041A80(s32, s32, s32);
extern s16  func_800419B0(s32);

s32 func_8002FDE8(s32 idx, s32 data) {

    extern s16 D_800A46D2;
    s16 r;
    s32 one;
    s32 i4;

    func_8002ED90();
    if (D_800A46A2 >= 0) {
        func_800415A8(D_800A46A2);
        D_800A46A2 = -1;
    }
    D_800A46A0 = idx | 0x4000;
    one = 1;
    __asm__ __volatile__("");
    D_800A46B0 = one;
    i4 = idx * 4;
    D_800A469C = *(s32 *)((u8 *)D_800652F0 + i4);
    r = func_80041A80(data, -1, D_800A469C);
    D_800A46D2 = r;
    D_800A46A2 = r;
    __asm__ __volatile__("");
    if (r == -1) {
        D_800A46B0 = one;
        return 1;
    }
    if (func_800419B0(r) == -1) {
        func_800415A8(D_800A46D2);
        D_800A46A2 = -1;
        D_800A46B0 = one;
        return 1;
    }
    D_800A46B0 = 0;
    return 1;
}
