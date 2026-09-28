/* Overlay range [8012EA90,8012EC04) from MAIN.CD member 0012.
 * SHA256(span)=073f5964918652575c2f62ceb6eadeb5aa67626881763dcfe5255f298e0c6d05.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012EA90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct { u32 a, b, c, d; } Blk16;
typedef struct { s16 h[8]; } Buf;
extern void func_80049CAC(s32 a0, s32 a1);

/* func_8012EA90 — shared body (overlay slot 0x80128158, h_exact fae86808). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
void func_8012EA90(s32 param_1, s32 param_2, s32 *param_3)
{
    Buf buf;
    s32 iVar4;
    register u32 v __asm__("$17");      /* $s1 */
    iVar4 = *(s32 *)(param_1 + 0x20);
    v = *(u32 *)(iVar4 + 0x20);
    if (v == 0) {
        *(Blk16 *)(param_3)        = *(Blk16 *)(iVar4 + 0x34);
        *(Blk16 *)((s32)param_3 + 0x10) = *(Blk16 *)(iVar4 + 0x44);
    } else if ((v & 0x1000000) != 0) {
        register s32 p __asm__("$16");
        s32 w;
        p = (s32)(v & 0xfeffffff);
        p = p + param_2 * 8;
        buf.h[0] = *(s16 *)(p + 6);
        w = *(s32 *)p;
        buf.h[1] = (s16)(*(u8 *)(p + 1) | ((w & 0xf) << 8));
        buf.h[2] = (s16)(((w >> 0x10) & 0xff) | ((w & 0xf0) << 4));
        func_80049CAC((s32)&buf, (s32)param_3);
        param_3[5] = *(s8 *)(p + 3);
        param_3[6] = *(s8 *)(p + 4);
        param_3[7] = *(s8 *)(p + 5);
    } else {
        s32 q;
        v = v + param_2 * 0xc;
        q = (s32)v;
        buf.h[0] = *(s16 *)(q + 6);
        buf.h[1] = *(s16 *)(q + 8);
        buf.h[2] = *(s16 *)(q + 0xa);
        func_80049CAC((s32)&buf, (s32)param_3);
        param_3[5] = *(s16 *)(q + 0);
        param_3[6] = *(s16 *)(q + 2);
        param_3[7] = *(s16 *)(q + 4);
    }
}
