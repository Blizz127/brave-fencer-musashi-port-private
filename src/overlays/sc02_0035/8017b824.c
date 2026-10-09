/* SC02.CD member35 [8017B824,8017B880): twin of main_0012 8017B824 (src/overlays/main_0012/8017b824.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [8017B824,8017B880) from MAIN.CD member 0012.
 * SHA256(span)=b7d559233f4fd38617c363ab79d7422f7b55a8271da12e08bce129d9710d82a7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B824 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801151D4;

void func_8017B824(void) {

    extern s32 D_801151D4;
    extern s16 D_801BE8C4;
    extern s16 D_801BE8C6;
    extern s16 D_801BE8C8;
    extern s16 D_801BE8CC;
    extern s16 D_801BE8CE;
    extern s16 D_801BE8D0;
    D_801BE8C4 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x48 ))) ;
    D_801BE8C6 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x4C ))) ;
    D_801BE8C8 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x50 ))) ;
    D_801BE8CC = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x3C ))) ;
    D_801BE8CE = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x40 ))) ;
    D_801BE8D0 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x44 ))) ;
}
