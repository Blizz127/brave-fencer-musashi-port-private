/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148E54 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004CFEC(s32, s32);

s32 func_80148E54(s32 arg0) {

    extern s32 D_801151D4;
    extern s16 (*D_8017FB4C[])();
    register s32 tmp __asm__("$4") = (func_8004CFEC(*(s32 *)(D_801151D4 + 0x44) - *(s32 *)(D_801151D4 + 0x50),
                                             *(s32 *)(D_801151D4 + 0x48) - *(s32 *)(D_801151D4 + 0x3C)) - 0x400) & 0xFFF;
    s32 ang;
    __asm__("" : "=r"(tmp) : "0"(tmp));
    ang = tmp;

    switch (*(u8 *)(arg0 + 0xA9)) {
    case 0x41:
        return D_8017FB4C[*(u16 *)(arg0 + 0xAA) >> 12]();
    case 0x53:
    case 0x73:
        if ((*(u16 *)(arg0 + 0xAE) & 0xFF) == 0x80 && (*(u16 *)(arg0 + 0xAE) >> 8) == 0x80) {
            return -1;
        }
        return (ang + func_8004CFEC((*(u16 *)(arg0 + 0xAE) & 0xFF) - 0x80,
                             0x80 - (*(u16 *)(arg0 + 0xAE) >> 8))) & 0xFFF;
    }
}
