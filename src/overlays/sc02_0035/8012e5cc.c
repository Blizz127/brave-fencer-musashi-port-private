/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012E5CC - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransPers func_8004955C
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 RotTransPers(s32, s32, s32 *, s32 *);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern u8 D_800AF648;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 RotTransPers(s32 a0, s32 a1, s32 *a2, s32 *a3);

void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3)
{
    struct { short xy[2]; int sp14; int flag; } f;
    register void *p __asm__("$4");
    p = &D_800AF648;
    func_8004914C(p);
    func_800491AC(&D_800AF648);
    RotTransPers(param_1, (s32)f.xy, &f.sp14, &f.flag);
    if (f.flag >= 0 && (u16)(f.xy[0] + 199) < 399 && (u16)(f.xy[1] + 0xA9) < 0x153) {
        func_8002D4C8(param_2, param_3);
    }
}
