/* Overlay range [8013B598,8013B6A0) from MAIN.CD member 0012.
 * SHA256(span)=238b1b40b21b86f586baa9703c39099132f0c6e26bd6b94cbc46eb1aad56ed21.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013B598 - byte-exact against retail at -O0 (tools/register_match.py). */
typedef struct { s32 f0; u16 f4; u16 f6; u16 f8; u16 fA; s32 fC; u8 pad[0xC]; } Spr_8013B598;
typedef struct { u16 f0; u16 f2; u16 f4; } Src_8013B598;

void func_8013B598(s32 a0, u16 *a1) {
    typedef struct { u16 f0; u16 f2; u16 f4; } Src_8013B598;
    typedef struct { s32 f0; u16 f4; u16 f6; u16 f8; u16 fA; s32 fC; u8 pad[0xC]; } Spr_8013B598;
    extern Spr_8013B598 D_80185B58[];

    D_80185B58[a0].f0 = 1;
    D_80185B58[a0].f4 = ((Src_8013B598 *)a1)->f0;
    D_80185B58[a0].f6 = ((Src_8013B598 *)a1)->f2;
    D_80185B58[a0].f8 = ((Src_8013B598 *)a1)->f4;
    D_80185B58[a0].fC = 0x100;
}
