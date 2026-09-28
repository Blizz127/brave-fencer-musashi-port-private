/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF6B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80178970(s32 *a0);
extern void func_80029124(s32 a0, s32 a1);
extern void func_80178D18(u8 *a0);
extern void func_801858F8(void *a0);

void func_801EF6B0(void *a0) {
    u16 v1;

    v1 = *(u16 *)((s32)a0 + 0x34);

    switch (v1) {
    case 0:
        if (func_80178970((s32 *)a0)) {
            func_80029124(0xEF, 1);
            func_80178D18((u8 *)a0);
            func_801858F8(a0);
        }
        break;
    case 1:
        if (func_80178970((s32 *)a0)) {
            func_80178D18((u8 *)a0);
            func_801858F8(a0);
        }
        break;
    }
}
