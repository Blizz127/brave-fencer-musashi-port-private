/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC024 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80047948(s32);
extern u8 D_800CC290[];
extern void func_80015954(s32 a0, s32 a1);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);

void func_800CC024() {
    extern u8 D_800CC290[];
    s32 s2;
    s32 s3;
    s32 m;
    s32 ang;
    s32 r;
    s16 d[2];
    u16 v;
    u16 t;
    s32 obj;

    {
        register s32 a0p __asm__("$4");
        obj = a0p;
    }

    s2 = *(s32 *)(obj + 0x4C);
    s3 = *(s32 *)(obj + 0x20);
    if (s2 == 0) {
        return;
    }

    func_80015954((s32)D_800CC290, obj + 4);

    v = *(u16 *)(obj + 0x60);
    m = v & 0x1F;
    ang = ((m << 8) & 0x7F00) >> 1;
    t = *(u16 *)(obj + 0xA);
    __asm__("" :: "r"(m), "r"(ang));
    *(u16 *)(obj + 0xA) = t - 0x10;
    *(u16 *)(obj + 0x60) = v + 1;

    if (*(s32 *)(obj + 0x50) == 0) {
        r = func_80047948(m << 7);
    } else {
        r = 0x1000 - func_80047948(m << 7);
    }
    d[0] = r / 1024;
    d[1] = func_8004787C(ang) / 512;

    *(u16 *)(obj + 6) += d[0];
    *(u16 *)(obj + 0xA) += d[1];
    *(s32 *)(s3 + 0x18) = *(s32 *)(*(s32 *)(s2 + 0x20) + 0x18);
}
