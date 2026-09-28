/* Overlay range [8016163C,80161774) from MAIN.CD member 0012.
 * SHA256(span)=7199fc46dde9e4fbad1a10f4186114ba4d84b7d64b5bfbeaf9721072bd131fba.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016163C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define ratan2 func_8004CFEC

/* func_8016163C — shared body (overlay slot 0x80128158, h_exact d743c21b). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20();
extern void func_8015BF48(s32 *a0);
extern s32 func_8014A6C4(s32 a0);
extern void func_8015F2F0(s32 *a0);
extern s32 ratan2(s32 a0, s32 a1);
extern s16 D_801152B0;
extern s16 D_801152B4;
s32 func_8016163C(s32 a0, u32 a1)
{
    s32 result;
    if ((a1 & 1) != 0) {
        func_801599A4(a0);
        func_80159B3C(a0);
        func_8014C010((s32)a0, 1);
        func_80161D20((s32)a0, *(u16 *)((s32)a0 + 0x16E));
        return 1;
    }
    if ((a1 & 0x4000) != 0) {
        func_801599A4(a0);
        func_8015BF48((s32 *)a0);
        func_8014C010((s32)a0, 1);
        func_80161D20((s32)a0, *(u16 *)((s32)a0 + 0x16E));
        return 2;
    }
    if ((a1 & 0x2000) != 0) {
        func_801599A4(a0);
        func_80159B3C(a0);
        func_8014C010((s32)a0, 1);
        func_80161D20((s32)a0, *(u16 *)((s32)a0 + 0x16E));
        return 4;
    }
    if ((a1 & 0x8000) != 0) {
        if (*(u16 *)((s32)a0 + 0x16C) != 0x15) {
            return 0;
        }
        if (func_8014A6C4((s32)a0) == 0) {
            return 0;
        }
        func_801599A4(a0);
        func_8015F2F0(a0);
        result = ratan2(D_801152B0, D_801152B4);
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = (s16)result;
        return 8;
    }
    return 0;
}
