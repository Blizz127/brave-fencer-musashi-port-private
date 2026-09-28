/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014DD8C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 func_80012A60(s32 a0, s32 a1);
extern s32 ratan2(s32, s32);
extern u8 D_801202A0[];
extern s32 ratan2(s32 x, s32 y);
extern s32 ratan2(s32 dx, s32 dy);
extern int func_80135A4C();
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);

s32 func_8014DD8C(s32 arg0, void *arg1, void *arg2) {
    extern u8 D_801202A0[];
    extern u8 D_80126720[];
    extern s32 ratan2(s32 a0, s32 a1);
    extern s32 func_80012A60(s32 a0, s32 a1);
    extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
    s16 temp_s0;
    s32 temp_s0_2;
    s16 temp_s1;
    s16 temp_v0;
    s16 temp_v1;
    s32 temp_a1;
    s8 *var_s2;
    s8 *var_s3;
    __asm__ __volatile__("" :: "r"(((void *)arg0)));
    temp_v0 = (*(  u16 * )((s8 *)( arg2 ) + (  0 )))  - (*(  u16 * )((s8 *)( arg1 ) + (  0 ))) ;
    temp_v1 = (*(  u16 * )((s8 *)( arg2 ) + (  4 )))  - (*(  u16 * )((s8 *)( arg1 ) + (  4 ))) ;
    if (((temp_v0 | temp_v1) << 0x10) != 0) {
        var_s3 = (s8 *) D_801202A0;
        if (var_s3 < var_s3 + 0x6480) {
            var_s2 = var_s3 + 0xE;
            __asm__ __volatile__("" :: "r"(var_s2));
loop_3:
            if ((*(  u16 * )((s8 *)( var_s3 ) + (  0 )))  != 0) {
                temp_a1 = (*(  s32 * )((s8 *)( var_s2 ) + (  0x4A ))) ;
                if ((temp_a1 != 0) && ((*(  u16 * )((s8 *)( var_s2 ) + (  0x4E )))  & 0x1000) && (func_80135A4C((*(  s32 * )((s8 *)( var_s2 ) + (  0x12 ))) , temp_a1, (s32 *)arg1, (s32)arg2) != 0)) {
                    temp_s1 = (*(  u16 * )((s8 *)( var_s2 ) + (  -8 )))  - (*(  u16 * )((s8 *)( ((void *)arg0) ) + (  6 ))) ;
                    temp_s0 = (*(  u16 * )((s8 *)( var_s2 ) + (  0 )))  - (*(  u16 * )((s8 *)( ((void *)arg0) ) + (  0xE ))) ;
                    temp_s0_2 = (s16) ratan2(temp_v1, temp_v0);
                    if ((s16) func_80012A60(temp_s0_2, (s16) ratan2(temp_s0, temp_s1)) < 0x400) {
                        (*(  s8 ** )((s8 *)( ((void *)arg0) ) + (  0x170 )))  = var_s3;
                        (*(  u16 * )((s8 *)( ((void *)arg0) ) + (  6 )))  = (u16) (*(  u16 * )((s8 *)( arg2 ) + (  0 ))) ;
                        (*(  s16 * )((s8 *)( ((void *)arg0) ) + (  0xA )))  = (s16) ((*(  u16 * )((s8 *)( arg2 ) + (  2 )))  + 0x10);
                        (*(  u16 * )((s8 *)( ((void *)arg0) ) + (  0xE )))  = (u16) (*(  u16 * )((s8 *)( arg2 ) + (  4 ))) ;
                        return 1;
                    }
                }
            }
            var_s3 += 0x10C;
            var_s2 += 0x10C;
            if ((u32) var_s3 >= (u32) D_80126720) {
                goto block_10;
            }
            goto loop_3;
        }
        return 0;
    }
block_10:
    return 0;
}
