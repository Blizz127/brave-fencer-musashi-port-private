/* Main-exec range [80026D64,80027058) from the SLUS executable.
 * SHA256(span)=ff46bad029d055eb59fe44ee85573a465c755efe108a961f0c557aab615b1dc3.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80026D64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 *D_800A5E60;

/* The five packet emitters live LATER in this TU with return types this function
 * cannot spell here (func_80027058/func_80027200 are `void` asm-block wrappers and
 * func_800279AC returns `LineG4 *`, a typedef declared below the INCLUDE_ASM site).
 * The §183 __asm__-label alias binds a locally-typed name to the real symbol, so the
 * call site keeps its `u8 *` result with no declaration conflict at the definitions. */
extern u8 *func_800273F4();
extern void *func_800275BC();
extern void *func_800277DC();
extern u8 *aF80027058() __asm__("func_80027058");
extern u8 *aF80027200() __asm__("func_80027200");
extern u8 *aF800279AC() __asm__("func_800279AC");

/* The per-case `p += count * K` (rather than one shared `adv` temp assigned in every
 * arm) is LOAD-BEARING, not style.  With a shared temp the switch end-label is a real
 * source label, so jump.c:1993's jump_chain path (`find_cross_jump(..., minimum=2)`)
 * pairs every `j` to it with every other and tail-merges five block groups that the
 * target keeps separate (-23 instructions).  Advancing `p` inside each arm makes the
 * shared `addu $s0,$s0,$v0` a CROSS-JUMP-CREATED label (`get_label_before`), whose
 * INSN_UID is >= max_uid — and jump.c:1988 guards the jump-to-jump search with
 * `INSN_UID (JUMP_LABEL (insn)) < max_uid`, so it never runs.  Only the minimum=1
 * "code before my own target label" path survives, which is exactly the one merge the
 * target does have: .L8002700C, the 0x28-flag arm folded into the 0x2D/0x2C tail. */
void func_80026D64(s32 arg0, s32 arg1, s32 arg2)
{
    u32 *hdr;
    u8 *p;
    s32 n;
    u8 *vtx;
    u8 *nrm;
    u32 w;
    s32 flg;
    s32 code;

    hdr = *(u32 **)(arg0 + 8);
    p = (u8 *)hdr[4];
    n = hdr[5];
    vtx = (u8 *)hdr[0];
    nrm = (u8 *)hdr[2];
    if (n == 0) {
        return;
    }
    do {
        w = *(u32 *)p;
        flg = (w >> 16) & 4;
        code = (w >> 24) & 0xFD;
        switch (code) {
        case 0x20:
            if (flg != 0) {
                D_800A5E60 = func_800273F4(p, vtx, nrm, D_800A5E60, *(u16 *)p, arg2,
                                           *(u32 **)(arg1 + 4));
                n -= *(u16 *)p;
                p += *(u16 *)p * 0x18;
            } else {
                D_800A5E60 = aF80027058(p, vtx, nrm, D_800A5E60, *(u16 *)p, arg2,
                                        *(u32 **)(arg1 + 4));
                n -= *(u16 *)p;
                p += *(u16 *)p * 0x10;
            }
            break;
        case 0x28:
            if (flg != 0) {
                D_800A5E60 = (u8 *)func_800275BC(p, vtx, nrm, D_800A5E60, *(u16 *)p, arg2,
                                                 *(u32 **)(arg1 + 4));
                n -= *(u16 *)p;
                p += *(u16 *)p * 0x20;
            } else {
                D_800A5E60 = aF80027200(p, vtx, nrm, D_800A5E60, *(u16 *)p, arg2,
                                        *(u32 **)(arg1 + 4));
                n -= *(u16 *)p;
                p += *(u16 *)p * 0x14;
            }
            break;
        case 0x24:
            n -= *(u16 *)p;
            p += *(u16 *)p * 0x18;
            break;
        case 0x30:
            n -= *(u16 *)p;
            p += *(u16 *)p * 0x14;
            break;
        case 0x38:
            n -= *(u16 *)p;
            p += *(u16 *)p * 0x18;
            break;
        case 0x34:
            n -= *(u16 *)p;
            p += *(u16 *)p * 0x1C;
            break;
        case 0x3C:
            n -= *(u16 *)p;
            p += *(u16 *)p * 0x24;
            break;
        case 0x25:
            D_800A5E60 = (u8 *)func_800277DC(p, vtx, nrm, D_800A5E60, *(u16 *)p, arg2,
                                             *(u32 **)(arg1 + 4));
            n -= *(u16 *)p;
            p += *(u16 *)p * 0x1C;
            break;
        case 0x2D:
            D_800A5E60 = aF800279AC(p, vtx, nrm, D_800A5E60, *(u16 *)p, arg2,
                                    *(u32 **)(arg1 + 4));
            n -= *(u16 *)p;
            p += *(u16 *)p * 0x20;
            break;
        case 0x2C:
            n -= *(u16 *)p;
            p += *(u16 *)p * 0x20;
            break;
        }
    } while (n != 0);
}
