/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEE40 - byte-exact against retail at -O2 (tools/register_match.py). */
#define VSync func_8004239C
extern u8 D_800B9A11;
extern s32 D_800B9A18;
extern u16 D_800B99E8;
extern s32 D_800D3ABC;
extern s32 D_800D3C0C;
extern s32 D_800D3C10;
extern void func_8001C044(void);
extern void func_80015310(void);
extern void func_800146B0(s32 a0);
extern void func_80059658(s32 a0);
extern s32 VSync(s32 a0);
extern void func_800167B8(s32 a0);
extern void func_800183E0(s32 *a0);
extern void func_800116E0(void);
extern s32 func_8001BFE8(void);
extern void func_80011928(s32 a0);
extern void func_8001BFF8(void);
extern void func_800118AC(void);

void func_800CEE40(void) {
    D_800B9A11 = 1;
    func_8001C044();
    func_80015310();
    func_800146B0(7);
    func_80059658(0);
    VSync(0);
    func_80059658(1);
    D_800B9A18 = 0;
    func_800167B8(0);
    func_800183E0(&D_800D3ABC);
    D_800D3C0C = 0;
    D_800D3C10 = 0;
    func_800116E0();
    D_800B99E8 = 0;
    if (func_8001BFE8() != 0) {
        func_80011928(3);
    } else {
        func_8001BFF8();
        func_800118AC();
    }
}
