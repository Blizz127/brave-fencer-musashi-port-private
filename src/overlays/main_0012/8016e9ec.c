/* Overlay range [8016E9EC,8016EAC0) from MAIN.CD member 0012.
 * SHA256(span)=c15e271062dd33d194dd2cf49eebbdd458ec9d22ed12b615abeebee590dde792.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E9EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_800D2CA8(int, int);
extern void func_800D2D10(int, int, void *, int);
extern s32 func_800D2CA8(s32 a0, s32 a1);
extern void func_800D2D10(s32 a0, s32 a1, void *a2, s32 a3);
extern s32 func_80024054(u8*, u8*);
extern void func_8016EC0C(s32 a0, s32 a1);

void func_8016E9EC(u8 *p)
{

    extern u8 *D_8018171C[];
    extern u8 D_80181734[];
    extern u16 D_80181738[];
    register u32 zr __asm__("$0");
    int i;
    int c;
    u8 *buf;
    u8 off;
    u16 h;
    s32 r;

    i = p[0] - 1;
    off = D_80181734[i];
    buf = D_8018171C[i];
    c = i + zr;
    r = func_800D2CA8(p[3], 0x1C);
    func_800D2D10(r, 1, buf + off, 0);
    ((s32 (*)(void *, void *))func_80024054)(buf, p + 8);
    p[3] = c;
    *(s16 *)(p + 4) = -0xD7;
    h = D_80181738[i];
    p[2] = 0;
    *(u16 *)(p + 6) = h;
    p[1] = p[1] + 1;
    ((void (*)(u8 *, s32))func_8016EC0C)(p, 0x80);
}
