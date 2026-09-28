/* Main-exec range [8002A2D4,8002A354) from the SLUS executable.
 * SHA256(span)=7d738daf4841091fc4649276078870993d6d60746426c3eeb54e5efaa093d2ac.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8002A2D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_8002A354(s32 arg0);
extern s32 func_8002A4B8(void);
extern void func_8016E918(s16 a0, s16 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002AAAC(void);
extern u8 D_800638FE[];

s32 func_8002A2D4(s32 arg0) {
    s32 i;
    s32 off;

    if (func_8002A354(arg0) != 0) {
        i = func_8002A4B8();
        off = i * 16;
        i = (i - 1) * 16;
        func_8016E918(1, *(u16 *)(D_800638FE + off) - *(u16 *)(D_800638FE + i));
        func_8002D4C8(0xB2C, 0);
        func_8002AAAC();
        return 1;
    }
    return 0;
}
