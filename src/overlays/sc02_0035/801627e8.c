/* SC02.CD member35 [801627E8,80162834): twin of main_0012 801627E8 (src/overlays/main_0012/801627e8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [801627E8,80162834) from MAIN.CD member 0012.
 * SHA256(span)=be0b217f2a1dcf2b1f0f3974387efba02ae46fefe18583bd0af528795f49133f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801627E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8011F750;

void func_801627E8(void)
{

    extern s32 D_8011F750;                
    extern void (*D_80187074[])(u8 *);    
    register u8 *p __asm__("$4") = (u8 *)&D_8011F750;
    s32 idx;

    __asm__ __volatile__("" : "=r"(p) : "0"(p));    
    idx = *p;
    if (idx != 0) {
        idx = idx - 1;
        D_80187074[idx](p);   /* retail jalr keeps a0 = &D_8011F750 */
    }
}
