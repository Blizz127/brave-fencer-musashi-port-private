/* SC02.CD member35 [80175268,801752BC): twin of main_0012 80175268 (src/overlays/main_0012/80175268.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80175268,801752BC) from MAIN.CD member 0012.
 * SHA256(span)=b1020d0db82e67f7463dfb697689df5caf8527f60f36f4e4e9191ae81186e7af.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80175268 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef void (*VoidFn)(void);
extern u8 D_80078EC0;
extern s32 (*D_80187B3C[])(void *);

s32 func_80175268(s32 param_1)
{

    extern u8 D_80078EC0;
    extern VoidFn D_80187B78[];
    *(u32 *)(param_1 + 0x44) |= 2;
    (*(VoidFn *)((s32)D_80187B78 + ((D_80078EC0 - 1) << 2)))();
}
