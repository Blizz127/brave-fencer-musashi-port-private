/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80147514 - byte-exact against retail at -O2 (tools/register_match.py). */
struct V4s80147514;
struct V4s80147514 { s16 a, b, c, d; };
extern s32 func_80012C6C(s32 a0, s32 a1, s32 a2);
extern s32 func_800129CC(s32 a0, s32 a1);

void func_80147514(s32 arg0) {
    s16 buf[8];
    *(struct V4s80147514 *)buf = *(struct V4s80147514 *)(arg0 + 0x120);
    if (((u16)buf[0] | (u16)buf[1] | (u16)buf[2]) == 0) {
        buf[1] = -0xFFF;
    }
    if (*(s16 *)(arg0 + 0x12E) != 0) {
        buf[0] = (u16)buf[0] + *(u16 *)(arg0 + 0x128);
        buf[1] = (u16)buf[1] + *(u16 *)(arg0 + 0x12A);
        buf[2] = (u16)buf[2] + *(u16 *)(arg0 + 0x12C);
    }
    *(s16 *)(arg0 + 0x118) = func_80012C6C(*(s16 *)(arg0 + 0x118), buf[0], 8);
    *(s16 *)(arg0 + 0x11A) = func_80012C6C(*(s16 *)(arg0 + 0x11A), buf[1], 8);
    *(s16 *)(arg0 + 0x11C) = func_80012C6C(*(s16 *)(arg0 + 0x11C), buf[2], 8);
    buf[0] = *(u16 *)(arg0 + 0x118);
    buf[1] = *(u16 *)(arg0 + 0x11A);
    buf[2] = *(u16 *)(arg0 + 0x11C);
    func_800129CC((s32)buf, arg0 + 0x100);
}
