/* Overlay range [801372B0,801375EC) from MAIN.CD member 0012.
 * SHA256(span)=f24091a1361be5a350a7fe568410c6fa0f07e4172c9a76b861723ca3c1128db7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801372B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define ApplyMatrixSV func_80048FBC

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define GsSortLine func_80051DC8

/* File-scope declarations from the vendor translation unit. */
typedef struct { s16 vx, vy, vz, pad; } Svec_801372B0;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef void (*code)(unsigned short *);
void func_8012A568(void (*a0)(void));
extern void func_8012A568(void (*a0)(void));
extern s16 D_800B9A02;
extern void GsSortLine(void *a0, void *a1, s32 a2);
void func_80137030(s16 a0, s16 a1);

/* func_801372B0 — shared body (overlay slot 0x80128158, h_exact 009f12cb). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
extern void ApplyMatrixSV(void *m, Svec_801372B0 *in, Svec_801372B0 *out);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8"); /* vendor: __asm__("GsSortLine") */
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern void func_80137178(s32 x, s32 y);
extern u8  D_800B9A11;
extern u8  D_800AF630[];
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern u8  D_800A6518[];
void func_801372B0(void) {
    Svec_801372B0 in;
    Svec_801372B0 out;
    Gline_801372B0 prim;
    register u8 *mat __asm__("$23") = D_800AF630;            /* $s7 = base; +0x18 after branch */
    register s32 white __asm__("$19");                       /* $s3, assigned lazily in-if */
    register s16 ax __asm__("$16");                          /* $s0 = out.vx+0x7B */
    register s16 ay __asm__("$17");                          /* $s1 = out.vx+0x75 */
    register s16 bx __asm__("$18");                          /* $s2 = out.vy-0x57 */
    register s16 by __asm__("$20");                          /* $s4 = out.vy-0x5D */
    in.vz = 0;
    in.vy = 0;
    in.vx = 0;
    if (D_800B9A11 != 1) {
        mat += 0x18;                                         /* addiu $s7, $s7, 0x18 (post-branch) */
        white = 0xFF;
        /* --- corner 0: +X axis, white line from (0x78,-0x5A) --- */
        in.vx = 0x10;
        ApplyMatrixSV(mat, &in, &out);
        {
            register s16 vx __asm__("$7") = out.vx;          /* $a3 */
            register s16 vy __asm__("$3") = out.vy;          /* $v1 */
            prim.attr = 0;                                   /* LEVER B: colors BEFORE x0 here — */
            prim.r = white; prim.g = white; prim.b = white;  /* drops the sb LUIDs below the x0  */
            prim.x0 = 0x78;                                  /* store -> white's S2 boost fires  */
            prim.y0 = -0x5A;                                 /* late -> li $s3,0xFF lands @31    */
            { s16 x1v = vx + 0x78; __asm__("" : "=r"(x1v) : "0"(x1v)); prim.x1 = x1v; }
            { s16 y1v = vy - 0x5A; __asm__("" : "=r"(y1v) : "0"(y1v)); prim.y1 = y1v; }
            aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        }
        /* --- corner 1: +X +6, red cross --- */
        in.vx = in.vx + 6;
        ApplyMatrixSV(mat, &in, &out);
        prim.attr = 0;
        prim.r = white; prim.g = 0; prim.b = 0;
        bx = out.vy;                                         /* $s2 = out.vy (load) */
        ay = out.vx;                                         /* $s1 = out.vx (load) */
        by = bx - 0x5D;                                      /* $s4 = out.vy - 0x5D */
        ax = ay + 0x7B;                                      /* $s0 = out.vx + 0x7B */
        bx = bx - 0x57;                                      /* $s2 = out.vy - 0x57 (in place) */
        {
        Gline_801372B0 *op = (Gline_801372B0*)&D_800A6518[(u32)aD800B9A02 * 0x14];
        __asm__("" : "=r"(op) : "0"(op));
        ay = ay + 0x75;                                      /* $s1 = out.vx + 0x75 (in place) */
        prim.x0 = ay; prim.y0 = by; prim.x1 = ax; prim.y1 = bx;
        aGsSortLine(&prim, op, 0);
        }
        __asm__("" : "=r"(ax) : "0"(ax));                    /* LEVER A: 2nd set kills ax's S2   */
        __asm__("" : "=r"(by) : "0"(by));                    /* boost (same for by) -> by/ax/bx/ */
        prim.attr = 0;                                       /* chain/ay revert to source order  */
        prim.r = white; prim.g = 0; prim.b = 0;
        prim.x0 = ax; prim.y0 = by; prim.x1 = ay; prim.y1 = bx;
        aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        /* --- corner 2: +Y axis, white line + sibling 030 --- */
        in.vx = 0;
        in.vy = 0x10;
        ApplyMatrixSV(mat, &in, &out);
        {
            register s16 vx __asm__("$7") = out.vx;          /* $a3 */
            register s16 vy __asm__("$2") = out.vy;          /* $v0 */
            prim.x0 = 0x78;
            prim.attr = 0;
            prim.r = white; prim.g = white; prim.b = white;
            prim.y0 = -0x5A;
            { s16 x1v = vx + 0x78; __asm__("" : "=r"(x1v) : "0"(x1v)); prim.x1 = x1v; }
            { s16 y1v = vy - 0x5A; __asm__("" : "=r"(y1v) : "0"(y1v)); prim.y1 = y1v; }
            aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        }
        in.vy = in.vy + 6;
        ApplyMatrixSV(mat, &in, &out);
        aF80137030((s32)(s16)(out.vx + 0x78), (s32)(s16)(out.vy - 0x5A));
        /* --- corner 3: +Z axis, white line + sibling 178 --- */
        in.vy = 0;
        in.vz = 0x10;
        ApplyMatrixSV(mat, &in, &out);
        {
            register s16 vx __asm__("$7") = out.vx;          /* $a3 */
            register s16 vy __asm__("$2") = out.vy;          /* $v0 */
            prim.x0 = 0x78;
            prim.attr = 0;
            prim.r = white; prim.g = white; prim.b = white;
            prim.y0 = -0x5A;
            { s16 x1v = vx + 0x78; __asm__("" : "=r"(x1v) : "0"(x1v)); prim.x1 = x1v; }
            { s16 y1v = vy - 0x5A; __asm__("" : "=r"(y1v) : "0"(y1v)); prim.y1 = y1v; }
            aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        }
        in.vz = in.vz + 6;
        ApplyMatrixSV(mat, &in, &out);
        func_80137178((s32)(s16)(out.vx + 0x78), (s32)(s16)(out.vy - 0x5A));
    }
    return;
}
