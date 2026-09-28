/* Main-exec range [80039DEC,80039F14) from the SLUS executable.
 * SHA256(span)=114e0708397033c9819f6a2f54d4cfacd2026efe57f5dfc917b50f1c3e5fdf7d.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80039DEC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80039DEC(a0, a1, a2)
    void *a0;
    s16 a1;
    s16 a2;
{
    u8 cnt;
    s32 tmp;

    switch (a2) {
    case 0x14: {
        u8 *p = (u8 *)a0 + a1 * 26;
        p[0x1F] = a2;
        p[0x22] = 0x18;
        p[0x21] |= 3;
        break;
    }
    case 0x1E:
        if (*(u8 *)((u8 *)a0 + 0x1F6) == 0) {
            *(u8 *)((u8 *)a0 + 0x1F9) = 1;
            return;
        }
        cnt = *(u8 *)((u8 *)a0 + 0x1F5);
        if ((u8)cnt != 0x7F) {
            *(u8 *)((u8 *)a0 + 0x1F5) = cnt + 0xFF;
            if ((u8)cnt == 0) {
                return;
            }
        }
        tmp = *(s32 *)((u8 *)a0 + 0xC);
        *(u8 *)((u8 *)a0 + 0x1F7) = a1 | 0xB0;
        *(s32 *)a0 = tmp;
        break;
    case 0x28: {
        u8 *p = (u8 *)a0 + a1 * 26;
        p[0x1F] = a2;
        p[0x22] = 0x1A;
        p[0x21] |= 3;
        break;
    }
    default: {
        u8 *p = (u8 *)a0 + a1 * 26;
        p[0x1F] = a2;
        p[0x21] |= 1;
        break;
    }
    }
}
