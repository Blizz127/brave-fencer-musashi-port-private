/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D878 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015954(s32 a0, s32 a1);
extern void func_8012EFB8(s32 a0);
extern u16 D_800B99DA;
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 cd;
} Col4_8017D878;

void func_8017D878(s32 a0) {
    s32 sp10[2];
    Col4_8017D878 col;
    s32 *owner;
    s32 t;

    extern u16 D_800B99DA;
    extern Col4_8017D878 D_80181D00;
    extern Col4_8017D878 D_80181D1C;
    extern Col4_8017D878 D_80181D38;
    extern Col4_8017D878 D_80181D54;

    owner = *(s32 **)(a0 + 0x20);

     

    if (((s32 (*)(s32, s32))func_8012EFB8)(a0 + 0xFC, (s32)sp10) & ~0x1000) {
        owner[1] |= 0x80000000;
    } else {
        owner[1] &= 0x7FFFFFFF;
    }

    func_80015954((s32)sp10, a0 + 4);

    t = (D_800B99DA & 1) << 2;
    col.r = t + 0x40;
    col.g = t + 0x40;
    col.b = t + 0x60;

    D_80181D00 = col;
    D_80181D1C = col;
    D_80181D38 = col;
    D_80181D54 = col;
}
