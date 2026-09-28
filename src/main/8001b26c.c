/* Main-exec range [8001B26C,8001B324) from the SLUS executable.
 * SHA256(span)=93ede75dcc5c7b45418a5025c064a2f5081de273d076a8ba89427305e4d40b4b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001B26C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define resLoad_curId D_800C6D34
#define resLoad_result D_800C6D10

extern s32 D_800BA1B4;
extern s32 resLoad_curId;
extern s32 resLoad_result;
extern s32 D_800C7C60;
extern s32 *D_800C7C64;
extern s32 D_800A2E20;
extern s32 D_800AEC78;
extern s32 func_8001AE90(s32 a0, s32 a1, s32 a2);
extern s32 func_8001ACF0(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4);

void func_8001B26C(void) {
    register s32 *s0 __asm__("$16");
    s32 v1;
    s32 tmp;

    if (resLoad_curId != 0) {
        goto exit;
    }

    s0 = &D_800C7C60;
    tmp = D_800BA1B4;
    *s0 = 0x8;
    D_800C7C64 = &D_800A2E20;

    if (tmp != 0) {
        if (tmp != 3) {
            v1 = 0;
            goto exit;
        }
        if (func_8001AE90(0, 0, (s32)&D_800AEC78) != 0) {
            goto set_flag;
        }
    }

    if (func_8001ACF0(0, 0, (s32 *)&D_800AEC78, 0, (s32)s0) == 0) {
        v1 = 0;
        goto exit;
    }

set_flag:
    D_800BA1B4 = 0;
    v1 = 1;

exit:
    resLoad_result = v1;
}
