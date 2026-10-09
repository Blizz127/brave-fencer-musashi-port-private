/* SC02.CD member35 [80178B70,80178BB8): twin of main_0012 80178B70 (src/overlays/main_0012/80178b70.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80178B70,80178BB8) from MAIN.CD member 0012.
 * SHA256(span)=6195aca52f7c72ebe8eb395af4e54331577430578e487a3badb4b57cf581f3f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178B70 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80178CBC(s32 a0, s32 a1);

s32 func_80178B70(s32 param_1, s32 param_2)
{
    extern void func_80178BF8();
    extern void func_80178CBC();
    extern int D_80187E0C;

    int *p = &D_80187E0C;
    *p = ((int)param_2);
    func_80178BF8();
    func_80178CBC(((int)param_1), p - 3);
}
