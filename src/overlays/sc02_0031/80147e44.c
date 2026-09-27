/* Complete SC02 retail span [80147E44,80147F50).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80147928(s32 a0, s32 a1);
extern void func_8014799C(s32 a0, s32 a1);
extern void func_80147A10(s32 a0, s32 a1);
extern void func_80013F3C(s32 a0);
extern void func_8004A0DC(s32 a0, s32 a1);
extern void func_80049F3C(s32 a0, s32 a1);
extern void func_8004A27C(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80147E44(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 out[3];
    s32 m[8];
    s32 *p0 = &D_80127090;
    s32 *p1 = &D_80127094;
    s32 *p2 = &D_80127098;
    s32 v = *(s32 *)(a0 + 0x20);

    func_80147928(a0, a1);
    func_8014799C(a0, a2);
    func_80147A10(a0, a3);
    func_80013F3C((s32)m);
    func_8004A0DC(*(s16 *)(v + 0x12), (s32)m);
    func_80049F3C(*(s16 *)(v + 0x10), (s32)m);
    func_8004A27C(*(s16 *)(v + 0x14), (s32)m);
    func_800484EC((s32)m, a0 + 0x24, (s32)out);
    D_80127090 = out[0];
    D_80127094 = out[1];
    D_80127098 = out[2];
    *(s32 *)(a0 + 0x10) = *p0;
    *(s32 *)(a0 + 0x14) = *p1;
    *(s32 *)(a0 + 0x18) = *p2;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
