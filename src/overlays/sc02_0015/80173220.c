/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80173220 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_80147324(s32 arg0);
extern void func_80019064(void *a0);
extern void func_80147324(s32 a0);
extern void func_80147324(int a);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern M2C_UNK D_801817BC;

void func_80173220(void * arg0)
{
    if ((*(  u16 * )((s8 *)( arg0 ) + (  0xB8 )))  & 0x4000) {
        func_80147324(0x516);
        func_80019064(&D_801817BC);
    }
    if ((*(  u16 * )((s8 *)( arg0 ) + (  0xB8 )))  & 0x8000) {
        func_80171A1C(arg0);
        func_80174650(arg0);
    }
}
