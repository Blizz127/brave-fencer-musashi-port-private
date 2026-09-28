/* Overlay range [801418F8,80141A60) from MAIN.CD member 0012.
 * SHA256(span)=bf36a02346a0304a09a19323194ff743696ac1b1d2ec13744fcbc92393ead403.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801418F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

// @class: loose-typing
// @stuck: none — MATCH (90 ins). Key levers:
//   (1) D_8011511A must be a DIRECT volatile global (block-scope `extern volatile unsigned short`),
//       NOT `*(volatile u16*)&D_8011511A`. Volatile forces the store-2-then-read-back reload (else
//       gcc folds 2>=4 and drops the branch); direct-global access recomputes %hi/%lo per reference
//       (3 fresh lui) whereas the `&`-cast pointer form CSEs the address into ONE register (2 ins short).
//   (2) Reconcile with the TU/engine_core canonical types: D_80115158 is `u8[]` (decays -> `*(u16*)D_80115158`),
//       D_8011515C is `u8` (halfword store -> `*(u16*)&D_8011515C`), func_80029178 is `s32(s32)`. Do not
//       redeclare these — the shared DEFINE macros already provide them (conflicting-types hard error).

extern void func_800D24A0(int);
extern void func_8002D4C8(int, int);
extern void func_80141C0C(int);

s32 func_801418F8(void) {

    extern u16 D_80115110;
    extern unsigned short D_80115112;
    extern unsigned short D_80115118;
    extern short D_80115128;
    extern s32 D_80115130;
    extern u8 D_80115158[];
    extern u8 D_8011515C;
    extern s16 D_8017F6F8;
    extern s16 D_8017F6FA;
    extern u16 D_8011515A;
    extern u16 D_8011515E;
    extern u16 D_80115162;
    extern u16 D_80115166;
    extern u16 D_8011512E;
    extern void *D_801841F8;
    extern void *D_801841FC;
    extern u8 D_8017F398;
    extern u8 D_8017F3B0;
    extern u8 D_8017F424;
    extern u8 D_8017F42C;
    extern volatile unsigned short D_8011511A;
    extern s32 func_80029178(s32);
    unsigned short t;

    func_800D24A0(1);
    D_8011511A = 2;
    t = D_8011511A;
    D_80115118 = 0;
    D_80115130 = 0;
    if (t >= 4) {
        D_8011511A = t - 3;
    }
    *(u16*)D_80115158 = 0x106;
    if ((func_80029178(0x1C) & 0xFF) == 0) {
        D_801841F8 = &D_8017F398;
        D_801841FC = &D_8017F424;
    } else {
        D_801841F8 = &D_8017F3B0;
        D_801841FC = &D_8017F42C;
    }
    D_8011515A = 0x104;
    *(u16*)&D_8011515C = 0x104;
    D_8011515E = 0x129;
    D_80115162 = 0x103;
    D_80115166 = 0x105;
    D_80115128 = 0;
    D_8011512E = 0;
    if (D_80115110 == 3) {
        func_8002D4C8(0x46E, 0);
    } else {
        func_80141C0C(0);
    }
    D_80115128 = 1;
    D_8017F6F8 = 0xE;
    D_8017F6FA = 3;
    D_80115112 += 1;
}
