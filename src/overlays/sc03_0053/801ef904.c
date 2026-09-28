/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF904 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80178CBC(s32, s32);
extern void func_80178CBC(s32 a0, s32 a1);
extern void func_8012E8E0(s32, s32);
extern void func_8012E88C(s32);
extern void func_80187344(s32);
extern short D_801F0900;

void func_801EF904(void *a0) {
    extern short D_801F0900;
    extern short D_801F0ACC;
    s32 s0 = (s32)a0;
    *(u16 *)((s32)a0 + 2) = 0xA;
    func_8012E8E0((s32)a0, (s32)&D_801F0900);
    func_8012E88C((s32)a0);
    func_80187344((s32)a0);
    func_80178CBC((s32 *)a0, (s32)&D_801F0ACC);
}
