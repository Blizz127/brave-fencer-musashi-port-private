/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B824 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801151D4;
extern s16 D_80196244;
extern s16 D_80196246;
extern s16 D_80196248;
extern s16 D_8019624C;
extern s16 D_8019624E;
extern s16 D_80196250;

void func_8017B824(void) {
    D_80196244 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x48 ))) ;
    D_80196246 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x4C ))) ;
    D_80196248 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x50 ))) ;
    D_8019624C = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x3C ))) ;
    D_8019624E = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x40 ))) ;
    D_80196250 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x44 ))) ;
}
