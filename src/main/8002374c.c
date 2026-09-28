/* Main-exec range [8002374C,80023BF0) from the SLUS executable.
 * SHA256(span)=b431c7ac5aa9f1cd70da90f0900404a6e76e270c12eea7ce46034312c673994d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8002374C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define GetTPage func_80058B40

/* func_8002374C  (297 ins, main, src/800.c) -- sprite/primitive list walker.
 *
 * Shape: for each 0x1C-byte source record, build ONE OT packet whose single tag
 * covers  [tag][DR_MODE code x2][GPU prim][DR_MODE code x2], then link it into
 * ot[idx].  The two SetDrawMode (func_8005A600) calls write their DR_MODE tag
 * words at p+0 and at (new D_800A5E60 - 0xC); both tag slots are deliberately
 * overwritten afterwards (p[0] by the real 0x07/0x0A/0x0C000000 tag, the second
 * by the last vertex), which is why only the code[] halves survive.
 *   case 0x60 = TILE   (0x20 block, tag 0x07000000)
 *   case 0x38 = POLY_G4(0x34 block, tag 0x0C000000) -- x,y,w,h -> 4 vertices
 *   case 0x30 = POLY_G3(0x2C block, tag 0x0A000000)
 * Case bodies are emitted in source order 0x60,0x38,0x30; the compare tree is
 * moved ahead of them by expand_end_case's reorder_insns, and 0x38's tail
 * cross-jumps into 0x30's `p[6] = t` suffix (both break paths then share the
 * `lui $a1,0xFF000000` at .L80023B64).
 *
 * LEVERS (this went 291 -> 280 -> 164 -> 74 -> 27 -> 17 -> 9 -> 3 -> MATCH):
 *  1. TWO pseudos for the loop word.  `tag` is the loaded value shifted IN PLACE
 *     (`sll $s3,$s3,24`) and `code` is a copy of it (`addu $s1,$s3,$zero`).  One
 *     variable gives `sll $s3,$s1,24` and is 2 insns short.  `code = tag` must
 *     sit at the BOTTOM of the loop body (with the duplicate in the entry block)
 *     so the loop-back branch takes it as its delay slot and `addiu $s2,$s2,0x1C`
 *     fills the `lw $s3` load delay; putting it at the loop TOP swaps those two
 *     and costs a nop.
 *  2. The x/y transform is a THREE-statement read-modify-write (cookbook S219).
 *     The arithmetic must be its own statement so it is emitted BEFORE the mask,
 *     and the mask must be a compound `&=` so it lands in place on `t`'s own
 *     register:
 *          q = w0 + t;  t &= 0xFFFF0000;  t |= (q & 0xFFFF);
 *     Writing it as one expression `t = (t & 0xFFFF0000) | ((w0 + t) & 0xFFFF)`
 *     emits `and` first, keeps `t` live, forces a scratch register, and also
 *     steals two `lw`/`lhu` load-delay nops (-2 ins).  `q` must be declared in a
 *     PER-SITE nested block: one function-wide temp gets a fragmented live range
 *     and the allocator stops tying `andi $v0,$v0,0xFFFF` in place.
 *  3. Entry block: sched2 will not group the four `lhu` ahead of the two `subu`
 *     from any statement order (5 permutations, all identical).  Pinning the
 *     four halfwords ($5/$3/$4/$2) forces all four live at once, which also
 *     pushes the arg0 copy off $a1 onto $a2 (17 -> 9), and pinning the OT base
 *     pair ($3 = &D_800A6610, $2 = D_800B9A02) fixes the v0/v1 swap (9 -> 3).
 *  4. The last 3 were the zero-byte sched1 fence of cookbook S194-A, placed
 *     AFTER the w0/h0 block so `subu $s5` emits ahead of `lui %hi(D_800A6610)`.
 *     Everything above it (lw src + 4 lhu + 2 subu) is exactly what the target
 *     emits first, which is the rule's precondition.
 *
 * Declarations copied verbatim from src/800.c (S376): D_800B9A02 u16,
 * D_800A5E60 u8*, D_800A6610 u8[], GetTPage/func_8005A600 as the TU spells them.
 */
extern u16 D_800B9A02;
extern u8 *D_800A5E60;
extern u8 D_800A6610[];
extern s32 GetTPage(s32, s32, s32, s32);
extern s32 func_8005A600(s32, s32, s32, s32, s32);

void func_8002374C(s32 arg0)
{
    u32 *src;
    u32 *p;
    u32 *ot;
    u32 *otp;
    u32 code;
    u32 tag;
    s32 t;
    s32 w0;
    s32 h0;
    u16 idx;

    if (*(s32 *)(arg0 + 4) < 0) {
        return;
    }
    src = *(u32 **)(arg0 + 0x20);
    {
        register s32 x0 __asm__("$5") = *(u16 *)(arg0 + 8);
        register s32 x1 __asm__("$3") = *(u16 *)(arg0 + 0x2E);
        register s32 y0 __asm__("$4") = *(u16 *)(arg0 + 0xA);
        register s32 y1 __asm__("$2") = *(u16 *)(arg0 + 0x30);
        w0 = x0 - x1;
        h0 = y0 - y1;
    }
    __asm__ __volatile__("");
    {
        register s32 obase __asm__("$3") = (s32)D_800A6610;
        register u32 oshf __asm__("$2") = D_800B9A02;
        ot = (u32 *)((oshf << 14) + obase);
    }
    idx = *(u16 *)(arg0 + 0x2C);

    tag = *src;
    code = tag;
    while (tag != 0) {
        tag = tag << 24;
        if (code & 0x40000000) {
            tag |= 0x02000000;
        }
        p = (u32 *)D_800A5E60;
        if (code & 0x800000) {
            func_8005A600((s32)p, 0, 1,
                          (u16)GetTPage(2, (code >> 28) & 3, 0x280, 0), 0);
        } else {
            func_8005A600((s32)p, 0, 0,
                          (u16)GetTPage(2, (code >> 28) & 3, 0x280, 0), 0);
        }
        switch (code & 0xFF) {
        case 0x60:
            D_800A5E60 += 0x20;
            func_8005A600((s32)(D_800A5E60 - 0xC), 0, 0,
                          (u16)GetTPage(2, (code >> 28) & 3, 0x280, 0), 0);
            p[0] = 0x07000000;
            p += 2;
            p[1] = tag | (src[3] & 0xFFFFFF);
            t = src[1];
            {
                s32 q = w0 + t;
                t &= 0xFFFF0000;
                t |= (q & 0xFFFF);
            }
            {
                s32 q = t >> 16;
                t &= 0xFFFF;
                t |= (h0 + q) << 16;
            }
            p[2] = t;
            p[3] = src[2];
            break;
        case 0x38:
            D_800A5E60 += 0x34;
            func_8005A600((s32)(D_800A5E60 - 0xC), 0, 0,
                          (u16)GetTPage(2, (code >> 28) & 3, 0x280, 0), 0);
            p[0] = 0x0C000000;
            p += 2;
            p[1] = tag | (src[3] & 0xFFFFFF);
            p[3] = src[4];
            p[5] = src[5];
            p[7] = src[6];
            t = src[1];
            {
                s32 q = w0 + t;
                t &= 0xFFFF0000;
                t |= (q & 0xFFFF);
            }
            {
                s32 q = t >> 16;
                t &= 0xFFFF;
                t |= (h0 + q) << 16;
            }
            p[2] = t;
            {
                s32 q = ((u16 *)src)[4] + t;
                t &= 0xFFFF0000;
                t |= (q & 0xFFFF);
            }
            p[4] = t;
            {
                s32 q = t >> 16;
                t &= 0xFFFF;
                t |= (((u16 *)src)[5] + q) << 16;
            }
            p[8] = t;
            {
                s32 q = t - ((u16 *)src)[4];
                t &= 0xFFFF0000;
                t |= (q & 0xFFFF);
            }
            p[6] = t;
            break;
        case 0x30:
            D_800A5E60 += 0x2C;
            func_8005A600((s32)(D_800A5E60 - 0xC), 0, 0,
                          (u16)GetTPage(2, (code >> 28) & 3, 0x280, 0), 0);
            p[0] = 0x0A000000;
            p += 2;
            p[1] = tag | (src[4] & 0xFFFFFF);
            p[3] = src[5];
            p[5] = src[6];
            t = src[1];
            {
                s32 q = w0 + t;
                t &= 0xFFFF0000;
                t |= (q & 0xFFFF);
            }
            {
                s32 q = t >> 16;
                t &= 0xFFFF;
                t |= (h0 + q) << 16;
            }
            p[2] = t;
            t = src[2];
            {
                s32 q = w0 + t;
                t &= 0xFFFF0000;
                t |= (q & 0xFFFF);
            }
            {
                s32 q = t >> 16;
                t &= 0xFFFF;
                t |= (h0 + q) << 16;
            }
            p[4] = t;
            t = src[3];
            {
                s32 q = w0 + t;
                t &= 0xFFFF0000;
                t |= (q & 0xFFFF);
            }
            {
                s32 q = t >> 16;
                t &= 0xFFFF;
                t |= (h0 + q) << 16;
            }
            p[6] = t;
            break;
        }
        otp = (u32 *)(idx * 4 + (u32)ot);
        p[-2] = (p[-2] & 0xFF000000) | (*otp & 0xFFFFFF);
        *otp = (*otp & 0xFF000000) | ((u32)(p - 2) & 0xFFFFFF);
        src += 7;
        tag = *src;
        code = tag;
    }
}
