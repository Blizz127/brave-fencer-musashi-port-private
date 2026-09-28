/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164DD0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015954(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);
extern void func_80148534(s32 a0, s32 a1);
extern void func_80149374(s32 arg0, s32 arg1);
extern void func_80149374(int, int);
extern void func_80149374(s32, s32);
extern void func_80148534(s32, s32);
extern void func_80015954(s32, s32);

void func_80164DD0(s32 a0) {
    s32 sp10[2];
    s32 sp18[2];
    s32 s2 = *(s32 *)(a0 + 0x4C);
    func_80148534((s32)sp10, (s32)sp18);
    func_80015954((s32)sp10, a0 + 4);
    func_80149374(s2, a0 + 4);
    *(s16 *)(a0 + 0xA) = *(u16 *)(a0 + 0xA) - 0x40;
}
