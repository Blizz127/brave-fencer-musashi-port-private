/* Overlay range [80137FD8,801380E0) from MAIN.CD member 0012.
 * SHA256(span)=876b1dc46c6a8705d5d1c4ef43fb8cdd6c8ffad6721b666712e96447363793b0.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80137FD8 - 66 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */


void func_80137FD8(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 v;
    u16 h30;
    *(u8 *)(a2 + 0x3) = 8;
    *(u8 *)(a2 + 0x7) = 0x3A;
    *(u8 *)(a2 + 0x4) = *(u8 *)(a1 + 0x0);
    *(u8 *)(a2 + 0x5) = *(u8 *)(a1 + 0x1);
    *(u8 *)(a2 + 0x6) = *(u8 *)(a1 + 0x2);
    *(u8 *)(a2 + 0xC) = *(u8 *)(a1 + 0x0);
    *(u8 *)(a2 + 0xD) = *(u8 *)(a1 + 0x1);
    *(u8 *)(a2 + 0xE) = *(u8 *)(a1 + 0x2);
    *(u8 *)(a2 + 0x14) = 0xFF;
    *(u8 *)(a2 + 0x15) = 0xFF;
    *(u8 *)(a2 + 0x16) = 0xFF;
    *(u8 *)(a2 + 0x1C) = 0xFF;
    *(u8 *)(a2 + 0x1D) = 0xFF;
    *(u8 *)(a2 + 0x1E) = 0xFF;
    h30 = *(u16 *)(a0 + 0x30);
    *(u16 *)(a2 + 0x18) = h30;
    *(u16 *)(a2 + 0x8) = h30;
    if (*(u32 *)(a0 + 0x8) & 0x2000) {
        v = (*(u16 *)(a0 + 0x30) + *(u16 *)(a0 + 0x34)) - 0xC;
        *(u16 *)(a2 + 0x20) = v;
        *(u16 *)(a2 + 0x10) = v;
    } else {
        s32 w = *(u16 *)(a0 + 0x30) + *(u16 *)(a0 + 0x34);
        *(u16 *)(a2 + 0x20) = w;
        *(u16 *)(a2 + 0x10) = w;
    }
    if (*(u8 *)(a1 + 0x3) == 0) {
        s32 hi = a3 + 0x5;
        *(u16 *)(a2 + 0x12) = a3;
        *(u16 *)(a2 + 0xA) = a3;
        *(u16 *)(a2 + 0x22) = hi;
        *(u16 *)(a2 + 0x1A) = hi;
        return;
    }
    {
        s32 lo = a3 + 0xC;
        register s32 hi __asm__("$3") = a3 + 0x5;
        *(u16 *)(a2 + 0x12) = lo;
        *(u16 *)(a2 + 0xA) = lo;
        *(u16 *)(a2 + 0x22) = hi;
        *(u16 *)(a2 + 0x1A) = hi;
    }
    __asm__ __volatile__("" ::: "memory");
}
