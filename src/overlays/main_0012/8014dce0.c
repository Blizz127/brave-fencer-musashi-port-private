/* Overlay range [8014DCE0,8014DD8C) from MAIN.CD member 0012.
 * SHA256(span)=34b6dcdbb56fe8afba8f938650f267a5132ca653ff51d7e03d6c1c24b267b297.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014DCE0 - byte-exact against retail at -O2 (tools/register_match.py). */
struct Quad;
struct Quad { s32 a, b, c, d; };
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80135888();
extern s32 func_80135888(s32, s32, s32, s32);
extern int func_80135888();

s32 func_8014DCE0(s32 arg0, s32 arg1, s32 arg2) {
    struct Quad buf;
    register s32 i __asm__("$17");
    register s32 s0 __asm__("$16");
    buf = *(struct Quad *)(*(u32 *)(arg0 + 0x58) & 0xFFFFFFF);
    i = 0;
    s0 = arg2;
    do {
        s32 r;
        r = func_80135888(*(s32 *)(arg0 + 0x20), (s32)&buf, arg1, s0);
        i += 1;
        if (r == 0) {
            s0 += 8;
        } else {
            return 1;
        }
    } while (i < 3);
    return 0;
}
