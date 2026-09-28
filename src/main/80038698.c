/* Exact retail word export for [80038698,800387C0); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80038698 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

s32 func_80038698(void *arg0) {
    u8 *p;
    register u32 len asm("$6");
    u32 hi;
    s32 div;

    p = *(u8 **)arg0;
    *(u8 **)arg0 = p + 1;
    len = p[0];
    *(u8 **)arg0 = p + 2;
    len |= p[1] << 8;
    *(u8 **)arg0 = p + 3;
    len |= p[2] << 16;
    *(u8 **)arg0 = p + 4;
    len |= p[3] << 24;
    if (len != 0x6468544D) {
        return -1;
    }
    *(u8 **)arg0 = p + 5;
    len = p[4];
    *(u8 **)arg0 = p + 6;
    len <<= 8;
    len |= p[5];
    *(u8 **)arg0 = p + 7;
    len <<= 8;
    len |= p[6];
    *(u8 **)arg0 = p + 8;
    len <<= 8;
    len |= p[7];
    hi = p[8];
    {
        u32 s = hi << 8;
        s |= p[9];
        if (s != 0) {
            return -1;
        }
    }
    hi = p[10];
    {
        u32 t = hi << 8;
        t |= p[11];
        if ((s16)t != 1) {
            return -1;
        }
    }
    hi = p[12];
    {
        u32 u = hi << 8;
        u |= p[13];
        div = (s16)u;
    }
    if (div & 0x8000) {
        return -1;
    }
    *(u16 *)((char *)arg0 + 0x1E6) = div & 0x7FFF;
    *(u8 **)arg0 += len;
    return 0;
}
