/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801365B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80126720[];
extern u8 D_801152A8[];
extern u8 D_8017F690;
extern u8 D_8017F68C;
extern s16 *D_8017F694;
extern u8 D_8017F698;

s32 func_801365B8(void *arg0, s32 arg1, s32 arg2) {
    extern u8 D_801152A8[];
    extern s16 D_801152AA;
    extern s16 D_801152AC;
    extern s16 D_80126722;
    extern s16 D_80126724;
    u16 *ac;
    s16 *b8;
    s16 *b4;
    s16 temp_v0;
    s16 temp_v1;
    s32 var_a3;
    s32 temp_a1;
    s32 var_a1;
    s32 var_v0;
    s32 var_v1;
    s32 a1c;
    s32 a2c;
    s32 cond;
    register u32 zr __asm__("$0");

    __asm__("addu %0,%1,$zero" : "=r"(a1c) : "r"(arg1));
    cond = arg1 & 1;
    a2c = arg2 + zr;
    if (!cond) {
        var_v1 = (s16) arg2 - (*(s16 **)&D_8017F68C)[0];
        var_a1 = var_v1;
        var_a3 = -(*(s16 **)&D_8017F698)[0];
    } else {
        var_a3 = (*(s16 **)&D_8017F698)[0];
        var_v1 = (*(s16 **)&D_8017F68C)[0] - (s16) arg2;
        var_a1 = -var_v1;
    }
    ac = *(u16 **)&D_8017F68C;
    b4 = D_8017F694;
    b8 = *(s16 **)&D_8017F698;
    b4[0] = ac[0] + var_a1;
    temp_a1 = -var_v1;
    b4[1] = ac[1] + (temp_a1 * b8[1]) / var_a3;
    temp_v0 = ac[2] + (temp_a1 * b8[2]) / var_a3;
    b4[2] = temp_v0;
    var_v0 = 0;
    if (temp_v0 < (*(  s16 * )((s8 *)( arg0 ) + (  0xC ))) ) {
        return var_v0;
    }
    if ((*(  s16 * )((s8 *)( arg0 ) + (  0xE )))  < temp_v0) {
        return var_v0;
    }
    temp_v1 = b4[1];
    if (temp_v1 < (*(  s16 * )((s8 *)( arg0 ) + (  8 ))) ) {
        return var_v0;
    }
    if ((*(  s16 * )((s8 *)( arg0 ) + (  0xA )))  < temp_v1) {
        return var_v0;
    }
    __asm__("" :: "r"(a1c));
    __asm__("" :: "r"(a1c));
    if (a1c & 0x8000) {
        b4[1] = (s16) (*(u16 **)&D_8017F690)[1];
        b4[2] = (s16) (*(u16 **)&D_8017F690)[2];
    }
    D_801152AC = 0;
    D_801152AA = 0;
    if ((a1c & 1) != 0) {
        *(s16 *)D_801152A8 = 0xFFF;
        (*(  s16 * )((s8 *)( D_8017F694 ) + (  0 )))  = a2c + 2;
    } else {
        *(s16 *)D_801152A8 = -0xFFF;
        (*(  s16 * )((s8 *)( D_8017F694 ) + (  0 )))  = a2c - 2;
    }
    *(s16 *)D_80126720 = (s16) ((s32) ((*(  s16 * )((s8 *)( arg0 ) + (  4 )))  + (*(  s16 * )((s8 *)( arg0 ) + (  6 ))) ) >> 1);
    D_80126722 = (s16) ((s32) ((*(  s16 * )((s8 *)( arg0 ) + (  8 )))  + (*(  s16 * )((s8 *)( arg0 ) + (  0xA ))) ) >> 1);
    var_v0 = 1;
    D_80126724 = (s16) ((s32) ((*(  s16 * )((s8 *)( arg0 ) + (  0xC )))  + (*(  s16 * )((s8 *)( arg0 ) + (  0xE ))) ) >> 1);
    return var_v0;
}
