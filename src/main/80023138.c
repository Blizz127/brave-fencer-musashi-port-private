/* Main-exec range [80023138,800233CC) from the SLUS executable.
 * SHA256(span)=f9d7c1f840c8dc4a5dd3de33f812607ad2553866e88ee00557d6c37c1680164a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80023138 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 *D_800A5E60;

void func_80023138(s32 *arg0, u8 *col, u8 *pts, u32 *ot)
{
    s32 frame_pad[12];
    u32 flags;
    u8 *p;
    s32 i;
    u32 maskAddr;
    u32 maskLen;
    u8 code;
    register u32 x __asm__("$3");
    u32 y;
    s32 h;
    register s32 *zp __asm__("$4");

    (void)&frame_pad;

    p = D_800A5E60;
    flags = arg0[1];
    D_800A5E60 = p + 0x1B0;
    code = (flags & 0x40000000) ? 0x3A : 0x38;

    i = 0;
    maskAddr = 0x00FFFFFF;
    maskLen = 0xFF000000;

    do {
        p[0x03] = 8;
        p[0x07] = code;
        p[0x04] = col[4];
        p[0x05] = col[5];
        p[0x06] = col[6];
        p[0x0C] = col[4];
        p[0x0D] = col[5];
        p[0x0E] = col[6];
        p[0x14] = col[0];
        p[0x15] = col[1];
        p[0x16] = col[2];
        p[0x1C] = col[0];
        p[0x1D] = col[1];
        p[0x1E] = col[2];
        *(u16 *)(p + 0x08) = *(u16 *)(pts + i * 4 + 0x4C);
        *(u16 *)(p + 0x0A) = *(u16 *)(pts + i * 4 + 0x4E);
        *(u16 *)(p + 0x10) = *(u16 *)(pts + i * 4 + 0x50);
        *(u16 *)(p + 0x12) = *(u16 *)(pts + i * 4 + 0x52);
        *(u16 *)(p + 0x18) = *(u16 *)(pts + i * 4 + 0x04);
        *(u16 *)(p + 0x1A) = *(u16 *)(pts + i * 4 + 0x06);
        *(u16 *)(p + 0x20) = *(u16 *)(pts + i * 4 + 0x08);
        *(u16 *)(p + 0x22) = *(u16 *)(pts + i * 4 + 0x0A);
        h = i >> 1;
        i++;
        zp = (s32 *)((h << 2) + (u32)pts);
        x = *(u32 *)p;
        y = ot[zp[13]];
        x &= maskLen;
        y &= maskAddr;
        x |= y;
        *(u32 *)p = x;
        ot[zp[13]] = (ot[zp[13]] & maskLen) | ((u32)p & maskAddr);
        p += 0x24;
    } while (i < 12);

    *(u16 *)(p - 0x14) = *(u16 *)(pts + 0x4C);
    *(u16 *)(p - 0x12) = *(u16 *)(pts + 0x4E);
    *(u16 *)(p - 0x04) = *(u16 *)(pts + 0x04);
    *(u16 *)(p - 0x02) = *(u16 *)(pts + 0x06);

    if (flags & 0x40000000) {
        u8 *r;
        register s32 j __asm__("$11");
        u32 e1;
        register u32 mA __asm__("$9");
        register u32 mL __asm__("$10");
        u8 one;

        r = p;
        j = 0;
        one = 1;
        e1 = ((flags >> 23) & 0x60) | 0xE1000000;
        mA = 0x00FFFFFF;
        mL = 0xFF000000;
        D_800A5E60 = D_800A5E60 + 0x60;
        do {
            h = j >> 1;
            j++;
            zp = (s32 *)((h << 2) + (u32)pts);
            r[0x03] = one;
            *(u32 *)(r + 4) = e1;
            x = *(u32 *)r;
            y = ot[zp[13]];
            x &= mL;
            y &= mA;
            x |= y;
            *(u32 *)r = x;
            ot[zp[13]] = (ot[zp[13]] & mL) | ((u32)r & mA);
            r += 8;
        } while (j < 12);
    }
}
