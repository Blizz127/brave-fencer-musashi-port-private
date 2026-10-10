/* Overlay range [80132F40,80133060) from MAIN.CD member 0012.
 * SHA256(span)=0945b9e9d876453a8723459abe8afd91d35067daf1bdde9224e1e1e222dcaef1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80132F40 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u16 vx, vy, vz, pad; } Svec_80132F40;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F038(int param_1, short *param_2, short *param_3);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888();
extern s32 func_80135888(s32, s32, s32, s32);
extern u8 D_80126BE0[];

void func_80132F40(s32 arg0)
{
    Svec_80132F40 v[4];
    register Svec_80132F40 *q __asm__("$17");
    register s16 *p __asm__("$2");
    register s32 h __asm__("$2");
    register s32 c __asm__("$2");
    register s32 hh __asm__("$4");
    s32 w;
    s32 m;
    q = &v[1];
    v[0].vx = D_80126B5E;
    v[0].vy = D_80126B62;
    v[0].vz = D_80126B66;
    v[1] = v[0];
    if (func_80135888(*(s32 *)(arg0 + 0x20), *(s32 *)(arg0 + 0x58),
                      (s32)D_80126BE0, (s32)q) != 0) {
        do { } while (0);
        p = (s16 *)((*(s32 *)(arg0 + 0x58) & 0x0FFFFFFF) | 0x80000000);
        w = p[4];
        h = p[5];
        hh = h;
        c = (h < w);
        if (c) { m = hh; } else { m = w; }
        func_8012F038(*(s32 *)(arg0 + 0x20) + 0x34, &v[0], q);
        v[1].vy = m;
        func_8012F14C(*(s32 *)(arg0 + 0x20) + 0x34, q, &v[0]);
        D_80126B5E = v[0].vx;
        D_80126B62 = v[0].vy;
        D_80126B66 = v[0].vz;
    }
}
