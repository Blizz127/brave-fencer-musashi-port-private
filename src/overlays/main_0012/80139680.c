/* Overlay range [80139680,80139788) from MAIN.CD member 0012.
 * SHA256(span)=f97fdc6c11149dde48f3d035a644c12aaef48d524bf7880ce80e4cec460e4450.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139680 - byte-exact against retail at -O2 (tools/register_match.py). */
#define GetTPage func_80058B40
extern s32 GetTPage(s32, s32, s32, s32);
extern s32 GetTPage(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80052460(s32 a0, s32 a1, s32 a2);

void func_80139680(s32 arg0, u8 * arg1)
{
    s32 buf[10];
    s32 var_s1;
    var_s1 = (s32)*(u16 *)((u8 *)arg0 + 0x12) - (s32)*(u16 *)((u8 *)arg0 + 0x16);
    if (var_s1 < 0) {
        var_s1 += 4;
    }
    *(s32 *)((u8 *)buf + 0x00) = 0;
    *(s16 *)((u8 *)buf + 0x0C) = GetTPage(0, 1, 0x1C0, 0x100);
    *(s16 *)((u8 *)buf + 0x10) = *(u16 *)((u8 *)arg0 + 0x3C);
    *(s16 *)((u8 *)buf + 0x12) = *(u16 *)((u8 *)arg0 + 0x3E);
    *(u8 *)((u8 *)buf + 0x16) = 0x80;
    *(u8 *)((u8 *)buf + 0x15) = 0x80;
    *(u8 *)((u8 *)buf + 0x14) = 0x80;
    {
        u16 idx = *(u16 *)((u8 *)arg0 + 0x14);
        s32 base = *(s16 *)((u8 *)arg0 + 0x30);
        s16 val;
        if (idx < 0x24) {
            val = idx * 6 + base;
        } else {
            val = base + 0xD2;
        }
        *(s16 *)((u8 *)buf + 0x04) = val;
    }
    *(s16 *)((u8 *)buf + 0x06) = *(u16 *)((u8 *)arg0 + 0x32) + var_s1 * 0xC;
    if (var_s1 != 0) {
        *(s16 *)((u8 *)buf + 0x06) = *(s16 *)((u8 *)buf + 0x06) + var_s1 * 2;
    }
    *(s16 *)((u8 *)buf + 0x08) = 0xC;
    *(s16 *)((u8 *)buf + 0x0A) = 0xC;
    *(u8 *)((u8 *)buf + 0x0E) = 0xF0;
    *(u8 *)((u8 *)buf + 0x0F) = 0;
    func_80052460((s32)buf, arg1, (s32)*(u16 *)((u8 *)arg0 + 0x1A));
}
