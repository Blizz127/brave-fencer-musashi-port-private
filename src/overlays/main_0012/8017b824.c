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
    extern s16 D_801853DC;
    extern s16 D_801853DE;
    extern s16 D_801853E0;
    extern s16 D_801853E4;
    extern s16 D_801853E6;
    extern s16 D_801853E8;
    D_801853DC = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x48 ))) ;
    D_801853DE = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x4C ))) ;
    D_801853E0 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x50 ))) ;
    D_801853E4 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x3C ))) ;
    D_801853E6 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x40 ))) ;
    D_801853E8 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x44 ))) ;
}
