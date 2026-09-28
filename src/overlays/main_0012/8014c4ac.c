/* Overlay range [8014C4AC,8014C568) from MAIN.CD member 0012.
 * SHA256(span)=78845b0ec30547710191ba15ef8bc27fd7f529fb5106416cb69efbef14e67e28.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C4AC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u16 a, b, c, d; } V4U_8014C4AC;
extern u16 D_801152B8;
extern u16 D_8012693A;
s32 aF8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4) __asm__("func_8014C4AC");
s32 aF8014C4AC() __asm__("func_8014C4AC");

s32 aF8014C4AC(a0, a1, a2, a3, a4)
s32 a0;
s32 a1;
s32 a2;
s16 *a3;
u16 a4;
{
    extern s32 D_80126CD0;
    extern u16 D_8012693A;
    extern u16 D_801152B8;
    u16 t;
    if (a0 == 0) {
        return 0;
    }
    if (*(u16 *)a0 == 0) {
        return 0;
    }
    if (a1 == 9 || a1 == 0x11 || a1 == 0x29 || a1 == 0xA || D_80126CD0 != a0) {
        t = *(u16 *)(a0 + 0x5C);
        *(u16 *)(a0 + 0x5E) = a1;
        *(u16 *)(a0 + 0x62) = a4;
        *(u16 *)(a0 + 0x60) = a2;
        *(u16 *)(a0 + 0x5C) = t | 1;
        *(V4U_8014C4AC *)(a0 + 0x7C) = *(V4U_8014C4AC *)a3;
        *(u8 *)(a0 + 0xC9) = D_8012693A;
        *(u8 *)(a0 + 0xC8) = D_801152B8;
        return a0;
    }
    return 0;
}
