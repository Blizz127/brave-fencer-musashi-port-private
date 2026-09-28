/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016BCC0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);
extern M2C_UNK D_8019565C;
extern M2C_UNK D_80195660;

void func_8016BCC0(void *arg0) {
    u16 temp_a2;
    u16 temp_v0;
    void *temp_s0;

    temp_s0 = (*(  void ** )((s8 *)( arg0 ) + (  0x20 ))) ;
    func_8016BF50();
    temp_a2 = (*(  u16 * )((s8 *)( arg0 ) + (  0x10 )))  + 0x60;
    (*(  u16 * )((s8 *)( arg0 ) + (  0x10 )))  = temp_a2;
    temp_v0 = (*(  u16 * )((s8 *)( temp_s0 ) + (  0x1A )))  + temp_a2;
    (*(  u16 * )((s8 *)( temp_s0 ) + (  0x1A )))  = temp_v0;
    (*(  u16 * )((s8 *)( temp_s0 ) + (  0x18 )))  = temp_v0;
    (*(  u16 * )((s8 *)( temp_s0 ) + (  0x12 )))  = (u16) (((*(  u16 * )((s8 *)( temp_s0 ) + (  0x12 )))  + 0x71) & 0xFFF);
    func_8016BFA8(arg0, &D_8019565C, &D_80195660, temp_s0 + 0x18);
    if ((s16) (*(  u16 * )((s8 *)( temp_s0 ) + (  0x1A )))  >= 0x1001) {
        (*(  u16 * )((s8 *)( temp_s0 ) + (  0x18 )))  = 0x1000U;
        (*(  u16 * )((s8 *)( temp_s0 ) + (  0x1A )))  = 0x1000U;
        func_80146E90(arg0, (*(  s32 * )((s8 *)( arg0 ) + (  0x30 ))) );
        (*(  u16 * )((s8 *)( arg0 ) + (  2 )))  = (u16) ((*(  u16 * )((s8 *)( arg0 ) + (  2 )))  + 1);
    }
}
