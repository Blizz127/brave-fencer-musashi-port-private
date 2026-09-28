/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80136824 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80126720[];
extern u8 D_801152A8[];
extern u8 D_8017E270;
extern u8 D_8017E26C;
extern s16 *D_8017E274;
extern u8 D_8017E278;

s32 func_80136824(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 D_801152A8[];
    extern s16 D_801152AA;
    extern s16 D_801152AC;
    extern s16 D_80126722;
    extern s16 D_80126724;

    register u16 *ac __asm__("$4");
    register s16 *b8 __asm__("$6");
    register s16 *b4 __asm__("$9");
    register s32 r __asm__("$3");
    register s32 pos __asm__("$12");
    register s32 a1v __asm__("$5");
    s16 temp_v0;
    s16 temp_v1;
    s32 var_a3;
    s16 var_v0_3;
    s32 temp_a1;
    s32 var_t0;
    s32 var_v1;
    s16 *b4b;
    u16 *p;

    __asm__ ("" : "=r"(a1v) : "0"(arg1));
    pos = arg2;
    if (!(a1v & 1)) {
        var_t0 = (s16) arg2 - (*(s16 **)&D_8017E26C)[1];
        var_v1 = var_t0;
        var_a3 = -(*(s16 **)&D_8017E278)[1];
    } else {
        var_a3 = (*(s16 **)&D_8017E278)[1];
        var_v1 = (*(s16 **)&D_8017E26C)[1] - (s16) arg2;
        var_t0 = -var_v1;
    }
    b8 = (*(s16 **)&D_8017E278);
    ac = (*(u16 **)&D_8017E26C);
    b4 = D_8017E274;
    temp_a1 = -var_v1;
    r = (temp_a1 * b8[0]) / var_a3;
    b4[0] = ac[0] + r;
    b4[1] = ac[1] + var_t0;
    r = (temp_a1 * b8[2]) / var_a3;
    temp_v0 = ac[2] + r;
    b4[2] = temp_v0;
    temp_v1 = b4[0];
    if (temp_v1 < (*(  s16 * )((s8 *)( ((void *)arg0) ) + (  4 ))) ) {
        return 0;
    }
    if ((*(  s16 * )((s8 *)( ((void *)arg0) ) + (  6 )))  < temp_v1) {
        return 0;
    }
    if (temp_v0 < (*(  s16 * )((s8 *)( ((void *)arg0) ) + (  0xC ))) ) {
        return 0;
    }
    if ((*(  s16 * )((s8 *)( ((void *)arg0) ) + (  0xE )))  < temp_v0) {
        return 0;
    }
    if (arg1 & 0x8000) {
        p = (*(u16 **)&D_8017E270);
        b4[0] = (s16) p[0];
        b4[2] = (s16) p[2];
    }
    D_801152AC = 0;
    (*(s16 *)D_801152A8) = 0;
    if (arg1 & 1) {
        b4b = D_8017E274;
        D_801152AA = 0xFFF;
        __asm__ __volatile__("");
        var_v0_3 = pos + 2;
    } else {
        b4b = D_8017E274;
        D_801152AA = -0xFFF;
        __asm__ __volatile__("");
        var_v0_3 = pos - 2;
    }
    b4b[1] = var_v0_3;
    __asm__ __volatile__("" :: "r"(pos));
    (*(s16 *)D_80126720) = (s16) ((s32) ((*(  s16 * )((s8 *)( ((void *)arg0) ) + (  4 )))  + (*(  s16 * )((s8 *)( ((void *)arg0) ) + (  6 ))) ) >> 1);
    D_80126722 = (s16) ((s32) ((*(  s16 * )((s8 *)( ((void *)arg0) ) + (  8 )))  + (*(  s16 * )((s8 *)( ((void *)arg0) ) + (  0xA ))) ) >> 1);
    D_80126724 = (s16) ((s32) ((*(  s16 * )((s8 *)( ((void *)arg0) ) + (  0xC )))  + (*(  s16 * )((s8 *)( ((void *)arg0) ) + (  0xE ))) ) >> 1);
    return 1;
}
