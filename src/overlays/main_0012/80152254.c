/* Overlay range [80152254,801522CC) from MAIN.CD member 0012.
 * SHA256(span)=07cfd91a9d29c342bf4edd8cfd65a66287a43da7523be882f64737f95a2b18fc.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80152254 - 30 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80149020(s32 *a0);
extern s32 func_80153800(s32 a0);
extern void func_80146D90(s32 a0);
extern void func_801522CC(s32 a0);
extern void func_80159B3C(void *a0);
extern void func_80165718(s32 a0);

void func_80152254(s32 *a0) {
    /* reserved stack local sets frame 0x28 (16-byte local region) */
    volatile s32 pad[4];
    func_80149020(a0);
    if (func_80153800((s32)a0) == 0) {
        *(u16 *)((u8 *)a0 + 0x4) = 0;
        *(u16 *)((u8 *)a0 + 0x8) = 0;
        *(u16 *)((u8 *)a0 + 0xC) = 0;
        *(u16 *)((u8 *)a0 + 0x6) = *(u16 *)((u8 *)a0 + 0x88);
        *(u16 *)((u8 *)a0 + 0xA) = *(u16 *)((u8 *)a0 + 0x8A);
        *(u16 *)((u8 *)a0 + 0xE) = *(u16 *)((u8 *)a0 + 0x8C);
        func_80146D90((s32)a0);
        func_801522CC((s32)a0);
        func_80159B3C((s32)a0);
        func_80165718((s32)a0);
    }
}
