/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801433F0 - byte-exact against retail at -O2 (tools/register_match.py). */
struct vec;
struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
extern void func_801292C8(u8 *a0);
extern void func_8012931C(struct vec *a0);
extern void func_80143458();
extern s32 func_80128ED8(s32 param_1, s32 *param_2);

void func_801433F0(s32 a0) {
    if (*(u16 *)(a0 + 2) == 0) {
        func_80143458();
    } else {
        func_8012931C((struct vec *)a0);
        if (func_80128ED8(*(void **)(a0 + 0x20), (u8 *)a0 + 0x24) != 0) {
            func_801292C8((u8 *)a0);
        }
    }
}
