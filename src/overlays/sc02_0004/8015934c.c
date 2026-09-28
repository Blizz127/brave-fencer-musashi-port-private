/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015934C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80145BF8(void);
extern void func_80146CA0(void *a0);
extern s32 D_801950F0;
extern int D_801950F0;
extern u8 D_800AE6BD;
extern s32 D_801950F8;

void func_8015934C(void *arg0) {
    void *temp_v1;

    if (D_801950F0 == 4) {
        D_801950F0 = 5;
    }
    if (D_801950F8 != 0) {
        func_80145BF8();
        func_80146CA0(arg0);
        D_800AE6BD += 1;
    }
    temp_v1 = (*(  void ** )((s8 *)( arg0 ) + (  0x20 ))) ;
    (*(  u16 * )((s8 *)( temp_v1 ) + (  0x12 )))  = (u16) (((*(  u16 * )((s8 *)( temp_v1 ) + (  0x12 )))  + 0x16) & 0xFFF);
}
