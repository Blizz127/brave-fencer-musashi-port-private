/* Main-exec range [8002A088,8002A108) from the SLUS executable.
 * SHA256(span)=ef1b886e1f6a8d4a27cff15c2805260a7fc03f7b484230e3aa6dd8174fdf5e13.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8002A088 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_8002A108();
extern s32 func_8002A26C(void);
extern void func_8016E918(s16 a0, s16 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002AAAC(void);
extern u8 D_800638FA[];

s32 func_8002A088(s32 arg0) {
    s32 i;
    s32 off;

    if (func_8002A108() != 0) {
        i = func_8002A26C();
        off = i * 16;
        i = (i - 1) * 16;
        func_8016E918(0, *(u16 *)(D_800638FA + off) - *(u16 *)(D_800638FA + i));
        func_8002D4C8(0xB2C, 0);
        func_8002AAAC();
        return 1;
    }
    return 0;
}
