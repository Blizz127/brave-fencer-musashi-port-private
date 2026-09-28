/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD204 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 func_8012A758(void);
extern s32 func_80013694(s16 a0, void *a1, void *a2);
extern void func_800139C8(s32 a0, void *a1, void *a2);
extern void func_80015954(void *a0, s32 a1);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern u8 D_800CD6BC[];

void func_800CD204(s32 arg0) {
    u16 sp10[3];
    s32 y;
    s32 x;
    s32 w;
    s32 t;
    s32 v1;
    s16 ang;

    y = *(s32 *)(arg0 + 0x4C);
    x = *(s32 *)(arg0 + 0x20);
    ang = func_8012A758();
    func_80013694(*(s16 *)(x + 0x10), D_800CD6BC, sp10);
    func_800139C8((s16)(ang + 0x400), sp10, sp10);
    w = *(s32 *)(y + 0x20);
    sp10[0] = sp10[0] + *(s32 *)(w + 0x48);
    t = sp10[1] - 0x20;
    sp10[1] = t + *(s32 *)(w + 0x4C);
    sp10[2] = sp10[2] + *(s32 *)(w + 0x50);
    v1 = func_80047948(*(s16 *)(arg0 + 0x60));
    if (v1 < 0) {
        v1 += 0x1FF;
    }
    sp10[0] = sp10[0] + (v1 >> 9);
    v1 = func_8004787C(*(s16 *)(arg0 + 0x60));
    if (v1 < 0) {
        v1 += 0xFF;
    }
    sp10[1] = sp10[1] + (v1 >> 8);
    *(u16 *)(arg0 + 0x60) = (*(u16 *)(arg0 + 0x60) + 0x38) & 0xFFF;
    func_80015954(sp10, arg0 + 4);
}
