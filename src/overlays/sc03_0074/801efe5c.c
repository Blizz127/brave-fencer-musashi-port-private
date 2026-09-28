/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFE5C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_80178B18(s32 a0, s32 a1);

void func_801EFE5C(void *a0) {
    extern s32 D_801F5EE4;
    extern s32 D_801C3890;
    extern s32 D_801F001C;
    extern u16 D_801EFFEC;
    extern u16 D_801EFFEE;
    extern u16 D_801EFFF0;
    s32 v0;
    s32 ptr;

    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
    } else {
        func_8001C214(v0, (s32)&D_801F5EE4);
        ptr = *(s32 *)((s32)a0 + 0x68);
        *(u16 *)((s32)a0 + 0x6) = D_801EFFEC;
        *(u16 *)((s32)a0 + 0xA) = D_801EFFEE;
        *(u16 *)((s32)a0 + 0xE) = D_801EFFF0;
        *(s16 *)(ptr + 0xC) = 0x7FFF;
        *(u16 *)((s32)a0 + 0x2) = 1;
        func_8012A828((s32)a0, (s32)&D_801C3890);
        *(u16 *)((s32)a0 + 0x34) = 0;
        func_80178B18((s32)a0, (s32)&D_801F001C);
    }
}
