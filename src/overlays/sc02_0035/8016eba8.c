/* SC02.CD member35 [8016EBA8,8016EC0C): twin of main_0012 8016EBA8 (src/overlays/main_0012/8016eba8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [8016EBA8,8016EC0C) from MAIN.CD member 0012.
 * SHA256(span)=e3de14ee3bd25e256ef7a1fba01ca72daca7d85f8d9d0a942e149d652dd21078.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016EBA8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016EC0C(s32 a0, s32 a1);

void func_8016EBA8(u8 *param_1)
{

    extern u16 D_80187890[];
    u8 c;

    *(u16 *)(param_1 + 4) =
        *(u16 *)(param_1 + 4) - D_80187890[param_1[2]];
    ((void (*)(u8 *, int))func_8016EC0C)(param_1, 0x80);
    c = param_1[2];
    param_1[2] = c + 0xFF;
    if (c == 0) {
        param_1[0] = 0;
    }
}
