/* Main-exec range [800226C0,80023138) from the SLUS executable.
 * SHA256(span)=ec0335578cbe480057ff6aa1171521852cca361a6dcfd46eae6ba6676985cabd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800226C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Typedefs copied from vendor src/800.c (func_80021D38 block). */
typedef struct { u16 vx, vy; } DVec_80021D38;              /* 4 bytes, align 2 */
typedef struct { s16 vx, vy, vz, pad; } SVec_80021D38;     /* 8 bytes */
typedef struct { s16 m[3][3]; s32 t[3]; } Mtx_80021D38;    /* 32 bytes */

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u32 flags;
    /* 0x08 */ SVec_80021D38 pos;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u16 sx;
    /* 0x1A */ u16 sy;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 *pts;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u16 depth;
    /* 0x2E */ u16 unk2E;
} Obj_80021D38;

/* func_800226C0 (main, src/800.c) — emit the 12-segment POLY_G4 strip for one Obj_80021D38
 * (plus the E1 draw-mode prims around it) into the D_800A5E60 bump allocator.
 *
 * Levers that closed it (S76y, from the S75 pinned draft at closeness 545 -> MATCH):
 *  - `t` is ONE plain `s16` local, read UNINITIALISED at the top (`sll $v0,$s2,16; beqz` =
 *    an HImode pseudo whose nonzero-bits are unknown before its set) and later assigned from
 *    the s32 `tt`; the `addu $v0,$s2,$zero; beqz $v0; addu $t2,$v0,$zero` chain at 228E4 is
 *    the sign-extension of that HImode pseudo folded to a copy (combine get_last_value) and
 *    then reused by cse2 for the loop's hoisted multiplier -- a pinned $18 can never do it
 *    (hard regs have no nonzero-bits).  `mul` must stay an unpinned pseudo (global alloc never
 *    coalesces a pseudo copy; a $10 pin swallows the $v0 temp).
 *  - `o`, `col`, `sh23`, `abr` unpinned: gcc's own param copies give the prologue order and the
 *    t/flags callee-saved order (density tie); the `or $v0,$v1,$v0` tie needs `abr` as a pseudo.
 *  - The !useIdx single-prim block at 850 is the inline addPrim form with block-local temps:
 *    a pinned `$a1` mask has reg_n_sets != 1 -> no birthing boost -> placed first in the block.
 * Symbols: only D_800A5E60 (14 %hi/%lo pairs in the .s) -- verified against the relocations.
 * The two struct typedefs are copies of src/800.c:12191-12209 for the standalone compile; the
 * harvest strips them (cdecl.typedef_names above the splice point).
 */


extern u8 *D_800A5E60;

void func_800226C0(Obj_80021D38 *arg0, u8 *col, DVec_80021D38 *pts, u8 *ot)
{
    s16 t;
    s16 work[24];
    u32 flags;
    u16 f16;
    s32 tt;
    s32 uu;
    s32 tsh;
    u32 sh23;

    u8 *p;
    u8 *s;
    u8 *w;
    u8 *e;
    s32 k;
    s32 m;
    s32 h;
    u32 x;
    u32 y;
    register u32 useIdx __asm__("$25");
    register u8 code __asm__("$24");
    register s32 i __asm__("$11");
    register s32 shadow __asm__("$17");
    register s32 *zp __asm__("$4");

    f16 = *(u16 *)((u8 *)arg0 + 0x1E);
    flags = arg0->flags;
    useIdx = f16 & 0x8000;
    shadow = 0;
    if (flags & 0x800000) {
        p = D_800A5E60;
        shadow = 1;
        if (useIdx) {
            if (t) {
                register u8 *q __asm__("$5");
                register u32 e1 __asm__("$13");
                register u8 one __asm__("$14");
                register u32 maskAddr __asm__("$10");
                register u32 maskLen __asm__("$12");

                D_800A5E60 = p + 0x60;
                i = 0;
                one = 1;
                e1 = 0xE1000000;
                maskAddr = 0x00FFFFFF;
                maskLen = 0xFF000000;
                q = p + 4;
                do {
                    h = i >> 1;
                    i++;
                    zp = (s32 *)((h << 2) + (u32)((u8 *)pts));
                    q[-1] = one;
                    *(u32 *)q = e1;
                    q += 8;
                    x = *(u32 *)p;
                    y = ((u32 *)ot)[zp[13]];
                    x &= maskLen;
                    y &= maskAddr;
                    x |= y;
                    *(u32 *)p = x;
                    ((u32 *)ot)[zp[13]] = (((u32 *)ot)[zp[13]] & maskLen) | ((u32)p & maskAddr);
                    p += 8;
                } while (i < 12);
            } else {
                register u8 *q __asm__("$10");
                register s32 *zq __asm__("$5");
                register u32 e1 __asm__("$14");
                register u8 one __asm__("$15");
                register u32 maskAddr __asm__("$12");
                register u32 maskLen __asm__("$13");

                D_800A5E60 = p + 0x30;
                i = 0;
                one = 1;
                e1 = 0xE1000000;
                maskAddr = 0x00FFFFFF;
                maskLen = 0xFF000000;
                q = p + 4;
                zq = (s32 *)((u8 *)pts);
                do {
                    i++;
                    q[-1] = one;
                    *(u32 *)q = e1;
                    q += 8;
                    x = *(u32 *)p;
                    y = ((u32 *)ot)[zq[13]];
                    x &= maskLen;
                    y &= maskAddr;
                    x |= y;
                    *(u32 *)p = x;
                    ((u32 *)ot)[zq[13]] = (((u32 *)ot)[zq[13]] & maskLen) | ((u32)p & maskAddr);
                    zq = (s32 *)((u8 *)zq + 4);
                    p += 8;
                } while (i < 6);
            }
        } else {
            D_800A5E60 = p + 8;
            p[3] = 1;
            *(u32 *)(p + 4) = 0xE1000000;
            *(u32 *)p = (*(u32 *)p & 0xFF000000) | (((u32 *)ot)[0] & 0x00FFFFFF);
            ((u32 *)ot)[0] = (((u32 *)ot)[0] & 0xFF000000) | ((u32)p & 0x00FFFFFF);
        }
    }

    f16 = *(u16 *)((u8 *)arg0 + 0x1E);
    p = D_800A5E60;
    tt = f16 & 0x1FFF;
    t = tt;
    D_800A5E60 = tt ? p + 0x1B0 : p + 0xD8;
    code = (flags & 0x40000000) ? 0x3A : 0x38;

    if (t) {
        {
            s32 mul;
            register s16 *dst __asm__("$5");
            register s16 *src __asm__("$4");

            i = 0;
            mul = t;
            dst = work;
            src = (s16 *)((u8 *)pts);
            do {
                *dst = *(s16 *)((u8 *)pts) + (((src[2] - *(s16 *)((u8 *)pts)) * mul) >> 12);
                dst[1] = *(s16 *)(((u8 *)pts) + 2) + (((src[3] - *(s16 *)(((u8 *)pts) + 2)) * mul) >> 12);
                i++;
                src += 2;
                dst += 2;
            } while (i < 12);
        }
        {
            register u32 maskAddr __asm__("$12");
            register u32 maskLen __asm__("$15");
            register s32 kk __asm__("$14");
            register u8 *ww __asm__("$13");
            register u8 *ss __asm__("$10");
            register u8 *d __asm__("$5");

            i = 0;
            maskAddr = 0x00FFFFFF;
            maskLen = 0xFF000000;
            d = p + 0x22;
            kk = 4;
            ww = (u8 *)work;
            ss = ((u8 *)pts);
            do {
                d[-0x1F] = 8;
                d[-0x1B] = code;
                d[-0x1E] = col[4];
                d[-0x1D] = col[5];
                d[-0x1C] = col[6];
                d[-0x16] = col[4];
                d[-0x15] = col[5];
                d[-0x14] = col[6];
                d[-0x0E] = col[0];
                d[-0x0D] = col[1];
                d[-0x0C] = col[2];
                d[-0x06] = col[0];
                d[-0x05] = col[1];
                d[-0x04] = col[2];
                *(u16 *)(d - 0x1A) = *(u16 *)(ss + 4);
                *(u16 *)(d - 0x18) = *(u16 *)(ss + 6);
                *(u16 *)(d - 0x12) = *(u16 *)(ss + 8);
                *(u16 *)(d - 0x10) = *(u16 *)(ss + 0xA);
                *(u16 *)(d - 0x0A) = *(u16 *)(ww);
                *(u16 *)(d - 0x08) = *(u16 *)(ww + 2);
                e = (u8 *)work + kk;
                *(u16 *)(d - 0x02) = *(u16 *)e;
                *(u16 *)(d) = *(u16 *)(e + 2);
                if (useIdx) {
                    h = i >> 1;
                    zp = (s32 *)((h << 2) + (u32)((u8 *)pts));
                    x = *(u32 *)p;
                    y = ((u32 *)ot)[zp[13]];
                    x &= maskLen;
                    y &= maskAddr;
                    x |= y;
                    *(u32 *)p = x;
                    ((u32 *)ot)[zp[13]] = (((u32 *)ot)[zp[13]] & maskLen) | ((u32)p & maskAddr);
                } else {
                    x = *(u32 *)p;
                    y = ((u32 *)ot)[0];
                    x &= maskLen;
                    y &= maskAddr;
                    x |= y;
                    *(u32 *)p = x;
                    ((u32 *)ot)[0] = (((u32 *)ot)[0] & maskLen) | ((u32)p & maskAddr);
                }
                kk += 4;
                ww += 4;
                ss += 4;
                i++;
                d += 0x24;
                p += 0x24;
            } while (i < 12);
        }

        *(u16 *)(p - 0x14) = *(u16 *)(((u8 *)pts) + 4);
        *(u16 *)(p - 0x12) = *(u16 *)(((u8 *)pts) + 6);
        *(u16 *)(p - 0x04) = *(u16 *)work;
        *(u16 *)(p - 0x02) = *(u16 *)((u8 *)work + 2);

        if (*(u16 *)((u8 *)arg0 + 0x1E) & 0x4000) {
            register u32 maskAddr __asm__("$10");
            register u32 maskLen __asm__("$15");
            register s32 mm __asm__("$14");
            register s32 kk __asm__("$13");
            register u8 *ww __asm__("$12");
            register u8 *d __asm__("$5");

            i = 0;
            maskAddr = 0x00FFFFFF;
            maskLen = 0xFF000000;
            mm = 8;
            kk = 4;
            p = D_800A5E60;
            ww = (u8 *)work;
            d = p + 0x22;
            D_800A5E60 = p + 0xD8;
            do {
                d[-0x1F] = 8;
                d[-0x1B] = code;
                d[-0x1E] = col[0x0C];
                d[-0x1D] = col[0x0D];
                d[-0x1C] = col[0x0E];
                d[-0x16] = col[0x0C];
                d[-0x15] = col[0x0D];
                d[-0x14] = col[0x0E];
                d[-0x0E] = col[0x08];
                d[-0x0D] = col[0x09];
                d[-0x0C] = col[0x0A];
                d[-0x06] = col[0x0C];
                d[-0x05] = col[0x0D];
                d[-0x04] = col[0x0E];
                *(u16 *)(d - 0x1A) = *(u16 *)(ww);
                *(u16 *)(d - 0x18) = *(u16 *)(ww + 2);
                e = (u8 *)work + kk;
                *(u16 *)(d - 0x12) = *(u16 *)e;
                *(u16 *)(d - 0x10) = *(u16 *)(e + 2);
                *(u16 *)(d - 0x0A) = *(u16 *)(((u8 *)pts));
                *(u16 *)(d - 0x08) = *(u16 *)(((u8 *)pts) + 2);
                e = (u8 *)work + mm;
                *(u16 *)(d - 0x02) = *(u16 *)e;
                *(u16 *)(d) = *(u16 *)(e + 2);
                if (useIdx) {
                    h = i >> 1;
                    zp = (s32 *)((h << 2) + (u32)work);
                    x = *(u32 *)p;
                    y = ((u32 *)ot)[zp[13]];
                    x &= maskLen;
                    y &= maskAddr;
                    x |= y;
                    *(u32 *)p = x;
                    ((u32 *)ot)[zp[13]] = (((u32 *)ot)[zp[13]] & maskLen) | ((u32)p & maskAddr);
                } else {
                    x = *(u32 *)p;
                    y = ((u32 *)ot)[0];
                    x &= maskLen;
                    y &= maskAddr;
                    x |= y;
                    *(u32 *)p = x;
                    ((u32 *)ot)[0] = (((u32 *)ot)[0] & maskLen) | ((u32)p & maskAddr);
                }
                mm += 8;
                kk += 8;
                ww += 8;
                i += 2;
                d += 0x24;
                p += 0x24;
            } while (i < 12);

            *(u16 *)(p - 0x04) = *(u16 *)work;
            *(u16 *)(p - 0x02) = *(u16 *)((u8 *)work + 2);
        }
    } else {
        register u32 maskAddr __asm__("$12");
        register u32 maskLen __asm__("$13");
        register u8 *ss __asm__("$10");
        register u8 *d __asm__("$5");

        i = 1;
        maskAddr = 0x00FFFFFF;
        maskLen = 0xFF000000;
        d = p + 0x22;
        ss = ((u8 *)pts) + 4;
        do {
            d[-0x1F] = 8;
            d[-0x1B] = code;
            d[-0x1E] = col[4];
            d[-0x1D] = col[5];
            d[-0x1C] = col[6];
            d[-0x16] = col[4];
            d[-0x15] = col[5];
            d[-0x14] = col[6];
            d[-0x0E] = col[0];
            d[-0x0D] = col[1];
            d[-0x0C] = col[2];
            d[-0x06] = col[4];
            d[-0x05] = col[5];
            d[-0x04] = col[6];
            *(u16 *)(d - 0x1A) = *(u16 *)(ss);
            *(u16 *)(d - 0x18) = *(u16 *)(ss + 2);
            *(u16 *)(d - 0x12) = *(u16 *)(ss + 4);
            *(u16 *)(d - 0x10) = *(u16 *)(ss + 6);
            *(u16 *)(d - 0x0A) = *(u16 *)(((u8 *)pts));
            *(u16 *)(d - 0x08) = *(u16 *)(((u8 *)pts) + 2);
            *(u16 *)(d - 0x02) = *(u16 *)(ss + 8);
            *(u16 *)(d) = *(u16 *)(ss + 0x0A);
            if (useIdx) {
                h = i >> 1;
                zp = (s32 *)((h << 2) + (u32)((u8 *)pts));
                x = *(u32 *)p;
                y = ((u32 *)ot)[zp[13]];
                x &= maskLen;
                y &= maskAddr;
                x |= y;
                *(u32 *)p = x;
                ((u32 *)ot)[zp[13]] = (((u32 *)ot)[zp[13]] & maskLen) | ((u32)p & maskAddr);
            } else {
                x = *(u32 *)p;
                y = ((u32 *)ot)[0];
                x &= maskLen;
                y &= maskAddr;
                x |= y;
                *(u32 *)p = x;
                ((u32 *)ot)[0] = (((u32 *)ot)[0] & maskLen) | ((u32)p & maskAddr);
            }
            ss += 8;
            i += 2;
            d += 0x24;
            p += 0x24;
        } while (i < 13);

        *(u16 *)(p - 0x04) = *(u16 *)(((u8 *)pts) + 4);
        *(u16 *)(p - 0x02) = *(u16 *)(((u8 *)pts) + 6);
    }

    if (flags & 0x40000000) {
        u32 abr;

        sh23 = flags >> 23;
        abr = sh23 & 0x60;
        if (useIdx) {
            i = 0;
            if (t) {
                register u8 *q __asm__("$5");
                u32 e1s;
                u32 e1n;
                register u8 one __asm__("$14");
                register u32 maskAddr __asm__("$9");
                register u32 maskLen __asm__("$10");

                one = 1;
                e1s = abr | 0xE1000200;
                e1n = abr | 0xE1000000;
                maskAddr = 0x00FFFFFF;
                maskLen = 0xFF000000;
                q = p + 4;
                D_800A5E60 = D_800A5E60 + 0x60;
                do {
                    q[-1] = one;
                    if (shadow) {
                        *(u32 *)q = e1s;
                    } else {
                        *(u32 *)q = e1n;
                    }
                    h = i >> 1;
                    i++;
                    zp = (s32 *)((h << 2) + (u32)((u8 *)pts));
                    q += 8;
                    x = *(u32 *)p;
                    y = ((u32 *)ot)[zp[13]];
                    x &= maskLen;
                    y &= maskAddr;
                    x |= y;
                    *(u32 *)p = x;
                    ((u32 *)ot)[zp[13]] = (((u32 *)ot)[zp[13]] & maskLen) | ((u32)p & maskAddr);
                    p += 8;
                } while (i < 12);
            } else {
                register u8 *q __asm__("$5");
                u32 e1s;
                u32 e1n;
                register u8 one __asm__("$14");
                register u32 maskAddr __asm__("$9");
                register u32 maskLen __asm__("$10");
                register s32 *zq __asm__("$6");

                one = 1;
                e1s = abr | 0xE1000200;
                e1n = abr | 0xE1000000;
                maskAddr = 0x00FFFFFF;
                maskLen = 0xFF000000;
                q = p + 4;
                D_800A5E60 = D_800A5E60 + 0x30;
                zq = (s32 *)((u8 *)pts);
                do {
                    q[-1] = one;
                    if (shadow) {
                        *(u32 *)q = e1s;
                    } else {
                        *(u32 *)q = e1n;
                    }
                    i++;
                    q += 8;
                    x = *(u32 *)p;
                    y = ((u32 *)ot)[zq[13]];
                    x &= maskLen;
                    y &= maskAddr;
                    x |= y;
                    *(u32 *)p = x;
                    ((u32 *)ot)[zq[13]] = (((u32 *)ot)[zq[13]] & maskLen) | ((u32)p & maskAddr);
                    zq = (s32 *)((u8 *)zq + 4);
                    p += 8;
                } while (i < 6);
            }
        } else {
            register u32 maskAddr __asm__("$4");
            register u32 maskLen __asm__("$5");

            D_800A5E60 = D_800A5E60 + 8;
            p[3] = 1;
            *(u32 *)(p + 4) = abr | (shadow ? 0xE1000200 : 0xE1000000);
            maskAddr = 0x00FFFFFF;
            maskLen = 0xFF000000;
            x = *(u32 *)p;
            y = ((u32 *)ot)[0];
            x &= maskLen;
            y &= maskAddr;
            x |= y;
            *(u32 *)p = x;
            ((u32 *)ot)[0] = (((u32 *)ot)[0] & maskLen) | ((u32)p & maskAddr);
        }
    }
}
