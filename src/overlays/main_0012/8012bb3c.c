/* Overlay range [8012BB3C,8012BC60) from MAIN.CD member 0012.
 * SHA256(span)=e2387b4b60633a23e37b28ebacd2a4864e7e041e032dd9470c1c85c492dd73fb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012BB3C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);

s32 func_8012BB3C(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    register s32 a __asm__("$17");    
    register s32 div __asm__("$16");  
    register s32 q __asm__("$3");     
    register s32 d __asm__("$2");     
    s32 ang;
    s32 diff;
    u32 cur;
    a = arg2;
    div = arg3;
    ang = ratan2(*(s16 *)(arg0 + 0xA) - *(s16 *)(arg1 + 0xA),
                 *(s16 *)(arg1 + 0x2) - *(s16 *)(arg0 + 0x2));
    ang = ang - 0x400;
    __asm__ __volatile__("" : : "r"(ang));
    div = (s16)div;
    a = a & 0xFFF;
    cur = ang & 0xFFF;
    if (a == cur) {
        d = 0;
    } else {
        s32 t;
        diff = cur - a;
        if (0x800 < diff) {
            t = a + 0x1000;
            diff = cur - t;
        }
        if (diff < -0x800) {
            t = a - 0x1000;
            diff = cur - t;
        }
        if (diff >= 0) {
            q = diff / div;
            if (q == 0) {
                q = 1;
            }
        } else {
            q = diff / div;
            if (q == 0) {
                q = -1;
            }
        }
        d = q;
    }
    return (s16)d;
}
