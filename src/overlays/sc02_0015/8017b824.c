/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B824 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801151D4;
extern s16 D_8019031C;
extern s16 D_8019031E;
extern s16 D_80190320;
extern s16 D_80190324;
extern s16 D_80190326;
extern s16 D_80190328;

void func_8017B824(void) {
    D_8019031C = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x48 ))) ;
    D_8019031E = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x4C ))) ;
    D_80190320 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x50 ))) ;
    D_80190324 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x3C ))) ;
    D_80190326 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x40 ))) ;
    D_80190328 = (s16) (*(  s32 * )((s8 *)( D_801151D4 ) + (  0x44 ))) ;
}
