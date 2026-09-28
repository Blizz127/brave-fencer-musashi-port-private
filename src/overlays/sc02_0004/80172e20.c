/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172E20 - byte-exact against retail at -O2 (tools/register_match.py). */
struct Src80172E20;
struct Src80172E20 {
    u8 pad0[6];
    u16 _6;
    u8 pad8[0xA - 8];
    u16 _A;
    u8 padC[0xE - 0xC];
    u16 _E;
};
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171A1C(u8 *a0);
extern s16 func_80171AB0(s32 param_1, void * _arg1);
extern s32 func_80174650(s32);
extern s32 D_80127508;

void func_80172E20(u8 * a0)
{
    struct Src80172E20 *p = (struct Src80172E20 *)D_80127508;
    u16 sp10[3];
    sp10[0] = p->_6;
    sp10[1] = p->_A;
    sp10[2] = p->_E;
    if (func_80171AB0(a0, sp10) == 0) {
        func_80171A1C((u8 *)a0);
        func_80174650(a0);
    }
}
