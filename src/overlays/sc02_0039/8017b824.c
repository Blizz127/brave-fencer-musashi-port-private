/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B824 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801151D4;
extern s16 D_801A0C74;
extern s16 D_801A0C76;
extern s16 D_801A0C78;
extern s16 D_801A0C7C;
extern s16 D_801A0C7E;
extern s16 D_801A0C80;

void func_8017B824(void) {
    D_801A0C74 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x48 ))) ;
    D_801A0C76 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x4C ))) ;
    D_801A0C78 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x50 ))) ;
    D_801A0C7C = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x3C ))) ;
    D_801A0C7E = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x40 ))) ;
    D_801A0C80 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x44 ))) ;
}
