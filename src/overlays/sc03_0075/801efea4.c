/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFEA4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 func_80178B18(s32 a0, s32 a1);

void func_801EFEA4(void *a0) {
    extern s32 D_801F66FC;
    extern s32 D_801F04B4;
    extern s16 D_801C3890;
    extern s32 D_801F050C;
    s32 v0;

    if ((u32)(func_80029504() - 0x122) < 0xA) {
        func_8012CAE4(a0);
        return;
    }

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
    } else {
        func_8001C214(v0, (s32)&D_801F66FC);
        *(s16 *)(*(s32 *)((s32)a0 + 0x68) + 0xC) = 0x7FFF;
        func_8012E8E0((s32)a0, (s32)&D_801F04B4);
        *(s16 *)((s32)a0 + 0x2) = 1;
        *(s16 *)((s32)a0 + 0x34) = 0;
        func_8012A828((s32)a0, (s32)&D_801C3890);
        func_80178B18((s32)a0, (s32)&D_801F050C);
    }
}
