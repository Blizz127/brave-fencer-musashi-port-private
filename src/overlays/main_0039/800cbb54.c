/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBB54 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32  func_80146E98(s32 a0);
extern s32 func_80146E98(s32 a0);
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_800CBBDC(s32 a0);
extern void func_800CBC40(void*, s32);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_800CBC10(void*);

void func_800CBB54(param_1)
s32 param_1;
{
    s32 p;
    s32 node;

    p = param_1;
    node = *(s32 *)(p + 0x20);
    ((void (*)(s32))func_800CBC10)(param_1);
    func_80128ED8(node, (s32 *)(p + 0x24));
    *(u8 *)(node + 0x27) = *(u8 *)(p + 0x28) - 0x70;
    ((void (*)(s32, s32))func_800CBC40)((void *)p, 0x40);
    *(s32 *)(p + 0x14) -= 0x4000;
    func_800CBBDC(p);
    if (func_80146E98(p) != 0) {
        ((void (*)(s32))func_80146C3C)(p);
    }
}
