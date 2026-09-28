/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165A78 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80165AC8(void);

void func_80165A78(s32 arg0)
{
    void *temp_a0;
    func_80165AC8();
    temp_a0 = (*(  void ** )((s8 *)( arg0 ) + (  0x20 ))) ;
    (*(  s8 * )((s8 *)( arg0 ) + (  0x197 )))  = 0;
    (*(  s32 * )((s8 *)( arg0 ) + (  0x44 )))  = (s32) ((*(  s32 * )((s8 *)( arg0 ) + (  0x44 )))  & ~8);
    (*(  u16 * )((s8 *)( temp_a0 ) + (  0x2C )))  = (u16) ((*(  u16 * )((s8 *)( temp_a0 ) + (  0x2C )))  & 0xFFDF);
}
