/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80136D08 - byte-exact against retail at -O2 (tools/register_match.py). */
#define AddPrim func_80058C6C
#define RotTransPers func_8004955C
#define SetLineG2 func_80058EB0
extern s32 AddPrim(s32, void *);
extern s32 RotTransPers(s32, s32, s32 *, s32 *);
extern void *func_80010A08(s32);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern s32 D_800A651C;
extern u8 D_800AF648;
extern s16 D_800B9A02;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 RotTransPers(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void SetLineG2(void *);

void func_80136D08(s32 arg0, s32 arg1) {
    s32 sp10;
    s32 sp14;
    s32 temp_v0;
    s32 temp_v0_2;
    void *buf;
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    buf = func_80010A08(0x14);
    SetLineG2(buf);
    *((u8 *)buf + 0xE) = 0xFF;
    *((u8 *)buf + 0x4) = 0xFF;
    *((u8 *)buf + 0xD) = 0x80;
    *((u8 *)buf + 0x5) = 0x80;
    *((u8 *)buf + 0xC) = 0x80;
    *((u8 *)buf + 0x6) = 0x80;
    temp_v0 = RotTransPers(arg0, (s32)buf + 8, &sp10, &sp14);
    temp_v0_2 = RotTransPers(arg1, (s32)buf + 0x10, &sp10, &sp14);
    temp_v0 = ((temp_v0 + temp_v0_2) >> 3) * 4;
    AddPrim(*(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + temp_v0, buf);
}
