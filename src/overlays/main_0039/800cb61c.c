/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB61C - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_800CB61C(s32 a0, s32 a1)
{
    typedef struct { u8 b[8]; } Blk8;
    extern u8 D_800CAE0C[8];
    extern s32 func_8014C5FC(s32, s32, void *);
    extern s32 func_8014C59C(void *, void *);
    extern s32 func_80012DBC(s32, s32, s32, s32);

    s32 s2 = *(s32 *)(a0 + 0x20);
    Blk8 buf;
    s32 r1, r2, x, y;

    buf = *(Blk8 *)D_800CAE0C;
    if (*(u16 *)a1 == 0x2CE) {
        *(s16 *)&buf.b[2] = -0x1AB;
    }
    r1 = func_8014C59C((void *)a0, (void *)a1);
    x = func_80012DBC(*(s16 *)(s2 + 0x12), (s16)r1, 0x10, 1);
    *(s16 *)(s2 + 0x12) = x;
    r2 = func_8014C5FC(a0, a1, &buf);
    y = func_80012DBC(*(s16 *)(s2 + 0x10), (s16)r2, 0x10, 1);
    *(s16 *)(s2 + 0x10) = y;
}
