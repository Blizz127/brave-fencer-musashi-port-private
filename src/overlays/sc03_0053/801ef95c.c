/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF95C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80178970(s32 *a0);
extern void func_80029124(s32 a0, s32 a1);
extern void func_80029514(s32 a0);
extern void func_80178D18(u8 *a0);
extern void func_80029124(s32, s32);
extern void func_80185924(void *a0);

void func_801EF95C(s32 *a0) {
    if (func_80178970(a0)) {
        func_80029124(0xE0, 0x1);
        func_80029514(0x1E);
        func_80178D18((u8 *)a0);
        func_80185924((void *)a0);
    }
}
