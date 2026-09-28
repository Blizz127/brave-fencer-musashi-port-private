/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD63C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern void func_80015A2C(s32 a0, s32 a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_80015954(s32 a0, s32 a1);
typedef struct { s32 w0, w1, w2, w3, w4, w5, w6, w7; } W8_;

void func_800CD63C(s32 a0, s32 a1)
{
    s16 sp10[3];
    s32 sp18[2];
    W8_ sp20;
    s32 t;
    s32 r;

    t = 0x20 - *(s32 *)(a0 + 0x1C);
    r = func_8004787C(*(s16 *)(a0 + 0x66));
    sp10[0] = ((((t << 17) >> 16) * r) / 4096);
    r = func_80047948(*(s16 *)(a0 + 0x66));
    sp10[1] = ((((t << 17) >> 16) * r) / 4096);
    sp10[2] = 0;

    sp20 = *(W8_ *)a1;

    func_80015A2C(a0 + 0x58, (s32)&sp20 + 0x14);
    func_8012F14C((s32)&sp20, (s32)sp10, (s32)sp18);
    func_80015954((s32)sp18, a0 + 4);

    *(u16 *)(a0 + 0x66) = (*(u16 *)(a0 + 0x66) + 0xE3) & 0xFFF;
}
