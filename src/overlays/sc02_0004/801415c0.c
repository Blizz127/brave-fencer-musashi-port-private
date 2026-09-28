/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801415C0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);
extern s32 func_800291DC(s32);
extern void func_800291C8(s32, s32);

void func_801415C0(s32 param_1, s32 param_2) {
    register s32 a __asm__("$16");   
    register s32 b __asm__("$17");   
    register s32 c __asm__("$18");   
    register s32 d __asm__("$19");   
    register s32 e __asm__("$20");   
    a = param_2;
    b = (s16)param_1;
    d = b + 0x2F;
    e = func_800291B4(d) & 0xFF;
    a = (s16)a;
    c = a + 0x2F;
    func_800291A0(d, func_800291B4(c) & 0xFF);
    func_800291A0(c, e);
    b = b * 2 + 0x14;
    e = func_800291DC(b);
    a = a * 2 + 0x14;
    func_800291C8(b, (s16)func_800291DC(a));
    func_800291C8(a, (s16)e);
}
