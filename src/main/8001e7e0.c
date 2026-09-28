/* Main-exec range [8001E7E0,8001EA14) from the SLUS executable.
 * SHA256(span)=536a228ca052a316aad9cb7feb535776ba84001b6e46c7cf52a739eafa400749.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001E7E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u16 D_800B9A02;
extern u8 D_800A6518[];
extern s32 func_80052460(s32 a0, s32 a1, s32 a2);

void func_8001E7E0(u8 *arg0)
{
    s32 buf[9];
    u16 ox, oy;
    u8 *otp;
    u8 *p;
    u32 attr;
    u32 pri;
    s32 shift;
    s32 mode;
    u32 sx, sy;
    u16 vx, vy;
    s32 vv;
    u16 tv;
    s32 tpage;
    u16 id;

    pri = *(u16 *)(arg0 + 0x2C) & 0x3FFF;
    if (pri < 0x1000) {
        p = *(u8 **)(arg0 + 0x20);
        ox = *(u16 *)(arg0 + 0x8);
        oy = *(u16 *)(arg0 + 0xA);
        attr = *(u32 *)(arg0 + 0x4);
        mode = (attr >> 24) & 3;
        shift = 2 - mode;
        otp = &D_800A6518[(u16)D_800B9A02 * 20];
        do {
            id = *(u16 *)p;
            sx = *(u16 *)(arg0 + 0x28) + (*(s16 *)(p + 4) >> shift);
            vx = sx;
            sy = *(u16 *)(arg0 + 0x2A) + *(u16 *)(p + 6);
            vy = sy;
            if (attr & 0x40000000) {
                tpage = (mode << 7) | (((attr >> 28) & 3) << 5) | ((sy & 0x100) >> 4) |
                        ((sx & 0x3C0) >> 6) | ((sy & 0x200) << 2);
            } else {
                tpage = (mode << 7) | (1 << 5) | ((sy & 0x100) >> 4) |
                        ((sx & 0x3C0) >> 6) | ((sy & 0x200) << 2);
            }
            buf[0] = attr;
            *(s16 *)((u8 *)buf + 0x04) =
                *(u16 *)(p + 8) + (ox + *(u16 *)(arg0 + 0x2E));
            *(s16 *)((u8 *)buf + 0x06) =
                *(u16 *)(p + 10) + (oy + *(u16 *)(arg0 + 0x30));
            *(s16 *)((u8 *)buf + 0x08) = *(u8 *)(p + 2);
            *(s16 *)((u8 *)buf + 0x0A) = *(u8 *)(p + 3);
            *(s16 *)((u8 *)buf + 0x0C) = tpage;
            *(u8 *)((u8 *)buf + 0x0E) = (vx - ((tpage & 0xF) << 6)) << shift;
            vv = vy;
            if (tpage & 0x10) {
                tv = vv - 0x100;
                *(u8 *)((u8 *)buf + 0x0F) = tv;
            } else {
                tv = vv;
                *(u8 *)((u8 *)buf + 0x0F) = tv;
            }
            *(s16 *)((u8 *)buf + 0x10) =
                (*(u8 *)(arg0 + 0x27) < 0xE0) ? 0x160 : 0x100;
            p += 12;
            *(s16 *)((u8 *)buf + 0x12) = *(u8 *)(arg0 + 0x27) + 0x100;
            *(u8 *)((u8 *)buf + 0x16) = 0x80;
            *(u8 *)((u8 *)buf + 0x15) = 0x80;
            *(u8 *)((u8 *)buf + 0x14) = 0x80;
            func_80052460((s32)buf, (s32)otp, (u16)pri);
        } while ((id & 0xFF) != 0xFF);
    }
}
