/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016BA68 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_8014C050(s32 a0, s32 a1);
extern void func_80146C3C();
extern void func_80146C3C(void);

s32 func_8016BA68(s32 arg0, s32 arg1) {
    extern s32 D_80126B58;
    s32 temp_v0;
    temp_v0 = func_8014C050(&D_80126B58, 0x56);
    if (temp_v0 != 0) {
        ((void (*)(void *))func_80146C3C)(temp_v0);
    }
    func_80146A6C(0x56, arg0, (*(  s16 * )((s8 *)( arg0 ) + (  0x7C ))) , (*(  s16 * )((s8 *)( arg0 ) + (  0x7E ))) , (s32) (*(  s16 * )((s8 *)( arg0 ) + (  0x80 ))) , arg1, 0);
}
