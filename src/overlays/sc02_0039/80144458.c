/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80144458 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern void func_8012AD80(s32 a0);
extern int func_80047948(int a0);
extern int func_8004787C(int a0);
extern void func_8012C218(void *a0);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 D_80180A28;

void func_80144458(void *arg0) {
    s32 temp_s0;
    void *temp_s2;
    void *temp_v0;

    temp_s2 = (*(  void ** )((s8 *)( arg0 ) + (  0xCC ))) ;
    if ((*(  s16 * )((s8 *)( arg0 ) + (  0x70 )))  == 0) {
        temp_v0 = (*(  void ** )((s8 *)( (*(  void ** )((s8 *)( arg0 ) + (  0x64 )))  ) + (  0x20 ))) ;
        if (temp_v0 != ((void *)0) ) {
            temp_s0 = ((*(  s16 * )((s8 *)( temp_v0 ) + (  0x12 )))  - 0x400) & 0xFFF;
            (*(  s32 * )((s8 *)( arg0 ) + (  0x10 )))  = (s32) (func_80047948(temp_s0) * D_80180A28 * 0x10);
            (*(  s32 * )((s8 *)( arg0 ) + (  0x18 )))  = (s32) (func_8004787C(temp_s0) * -D_80180A28 * 0x10);
            func_8012AD80(arg0);
        }
    }
    (*(  u16 * )((s8 *)( temp_s2 ) + (  8 )))  = (u16) (*(  u16 * )((s8 *)( arg0 ) + (  6 ))) ;
    (*(  u16 * )((s8 *)( temp_s2 ) + (  0xA )))  = (u16) (*(  u16 * )((s8 *)( arg0 ) + (  0xA ))) ;
    (*(  u16 * )((s8 *)( temp_s2 ) + (  0xC )))  = (u16) (*(  u16 * )((s8 *)( arg0 ) + (  0xE ))) ;
    if (func_80128ED8(temp_s2, arg0 + 0xD0) != 0) {
        func_80016714(temp_s2, 0x38);
        func_8012C218(arg0);
    }
}
