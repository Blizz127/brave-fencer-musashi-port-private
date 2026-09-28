/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBD90 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);
extern void func_80146C3C();
extern s32 func_80128ED8(s32 param_1, s32 *param_2);

void func_800CBD90(void *arg0) {
    s32 q;
    u8 a;
    u8 b;
    u16 h;

    q = *(s32 *)((s32)arg0 + 0x20);

    a = *(u8 *)(q + 0x24) - 0x20;
    *(u8 *)(q + 0x24) = a;
    if (a < 0x80) {
        *(u8 *)(q + 0x24) = 0x80;
    }

    b = *(u8 *)(q + 0x25) + 0x20;
    *(u8 *)(q + 0x25) = b;
    if (b > 0x80) {
        *(u8 *)(q + 0x25) = 0x80;
    }

    h = *(u16 *)(q + 0x1A) + 0x400;
    *(u8 *)(q + 0x26) = *(u8 *)(q + 0x25);
    *(u16 *)(q + 0x1A) = h;
    *(u16 *)(q + 0x18) = h;

    if (func_80128ED8(q, (s32 *)((s32)arg0 + 0x24)) != 0) {
        ((void (*)(void *))func_80146C3C)(arg0);
    }
}
