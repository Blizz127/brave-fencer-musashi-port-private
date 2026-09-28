/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012E688 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransPers func_8004955C
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 RotTransPers(s32, s32, s32 *, s32 *);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern u8 D_800AF648;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 RotTransPers(s32 a0, s32 a1, s32 *a2, s32 *a3);

void func_8012E688(s32 param_1, u16 param_2, u16 param_3)
{
    struct { short v[3]; short pad; short xy[2]; int sp1c; int flag; } f;
    register void *p __asm__("$4");
    register u16 a __asm__("$16") = param_2;
    register u16 b __asm__("$17") = param_3;
    if (*(s32 *)(param_1 + 0x20) != 0) {
        f.v[0] = (short)*(s32 *)(*(s32 *)(param_1 + 0x20) + 0x48);
        f.v[1] = (short)*(s32 *)(*(s32 *)(param_1 + 0x20) + 0x4C);
        f.v[2] = (short)*(s32 *)(*(s32 *)(param_1 + 0x20) + 0x50);
        p = &D_800AF648;
        func_8004914C(p);
        func_800491AC(&D_800AF648);
        RotTransPers((s32)f.v, (s32)f.xy, &f.sp1c, &f.flag);
        if (f.flag < 0) {
            return;
        }
        if ((u16)(f.xy[0] + 199) >= 399) {
            return;
        }
        if ((u16)(f.xy[1] + 0xA9) >= 0x153) {
            return;
        }
    }
    func_8002D4C8(a, b);
}
