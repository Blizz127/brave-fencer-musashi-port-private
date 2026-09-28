/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80134C20 - byte-exact against retail at -O2 (tools/register_match.py). */
#define VectorNormalSS func_80047E98
extern u8 D_801152A8[];
extern s32 VectorNormalSS(void *a0, void *a1);

s32 func_80134C20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 func_80134FB8(s32 a0, s32 a1, s32 a2);
    extern void * D_8017F68C;
    extern void * D_8017F690;
    extern void * D_8017F694;
    extern void * D_8017F698;
    extern u16 D_8019F9C8;

    s32 temp_a3;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    u16 temp_a1;
    s32 temp_s4;
    s32 c = arg0;
    __asm__ __volatile__("" : "=r"(c) : "0"(c));
    __asm__ __volatile__("" : : "r"(arg0));

    temp_s4 = arg2 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  2 )))  * 8);
    temp_s1 = *(s32 *)(arg3 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  4 )))  * 4));
    var_v0 = 0;
    if (func_80134FB8(temp_s4, (s32) D_8017F690, temp_s1) >= 0) {
        return var_v0;
    }
    temp_v0 = func_80134FB8(temp_s4, (s32) D_8017F68C, temp_s1);
    if (temp_v0 < 0) {
        goto block_13;
    }
    temp_v0_2 = func_80134FB8(temp_s4, (s32) D_8017F698, 0);
    temp_a3 = -temp_v0;
    {
        u16 *pB4 = (u16 *)D_8017F694;
        u16 *pAC = (u16 *)D_8017F68C;
        s16 *pB8 = (s16 *)D_8017F698;
        pB4[0] = pAC[0] + (temp_a3 * pB8[0]) / temp_v0_2;
        pB4[1] = pAC[1] + (temp_a3 * pB8[1]) / temp_v0_2;
        pB4[2] = pAC[2] + (temp_a3 * pB8[2]) / temp_v0_2;
        var_v0 = 0;
        if (func_80134FB8(arg2 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  6 )))  * 8), (s32) pB4, *(s32 *)(arg3 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  8 )))  * 4))) < -0x2F00) {
            return var_v0;
        }
    }
    var_v0 = 0;
    if (func_80134FB8(arg2 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  0xA )))  * 8), (s32) D_8017F694, *(s32 *)(arg3 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  0xC )))  * 4))) < -0x2F00) {
        return var_v0;
    }
    var_v0 = 0;
    if (func_80134FB8(arg2 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  0xE )))  * 8), (s32) D_8017F694, *(s32 *)(arg3 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  0x10 )))  * 4))) < -0x2F00) {
        return var_v0;
    }
    if ((arg0 << 16) < 0) {
        var_v0 = 0;
        if (func_80134FB8(arg2 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  0x12 )))  * 8), (s32) D_8017F694, *(s32 *)(arg3 + ((*(  s16 * )((s8 *)( ((void *)arg1) ) + (  0x14 )))  * 4))) < -0x2F00) {
            return var_v0;
        }
    }
    if (c & 1) {
        if (!((*(  u16 * )((s8 *)( ((void *)arg1) ) + (  0 )))  & 0x300)) {
            goto block_14;
        }
        return 0;
    }
    temp_a1 = (*(  u16 * )((s8 *)( ((void *)arg1) ) + (  0 ))) ;
    if (!(temp_a1 & 0x200)) {
        goto block_14;
    }
    D_8019F9C8 = temp_a1;
block_13:
    return 0;
block_14:
    __builtin_memcpy(D_801152A8, (void *)temp_s4, 8);
    VectorNormalSS(D_8017F698, D_8017F698);
    {
        u16 *pB8 = (u16 *)D_8017F698;
        u16 *pB4b = (u16 *)D_8017F694;
        pB4b[0] = pB4b[0] - ((pB8[0] << 0x10) >> 0x1B);
        var_v0 = 1;
        pB4b[1] = pB4b[1] - ((pB8[1] << 0x10) >> 0x1B);
        pB4b[2] = pB4b[2] - ((pB8[2] << 0x10) >> 0x1B);
    }
    return var_v0;
}
