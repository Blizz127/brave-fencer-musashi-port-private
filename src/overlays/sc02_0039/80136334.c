/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80136334 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80126720[];
extern u8 D_801152A8[];
extern u8 D_8017F690;
extern u8 D_8017F68C;
extern s16 *D_8017F694;
extern u8 D_8017F698;

s32 func_80136334(void *arg0, s32 arg1, s32 arg2) {
    extern u8 D_801152A8[];
    extern s16 D_801152AA;
    extern s16 D_801152AC;
    extern s16 D_80126722;
    extern s16 D_80126724;
    register s32 a1v __asm__("$11");
    register s32 a2v __asm__("$12");
    register s32 n __asm__("$5");
    register s16 *b4 __asm__("$7");
    s32 d;
    s32 dx;
    s32 denom;
    s32 result;
    s32 frame_pad[2];
    (void)&frame_pad;
    __asm__("" : "=r"(a1v) : "0"(arg1));
    a2v = arg2;

    if (!(arg1 & 1)) {
        dx = (s16) arg2 - (*(s16 **)&D_8017F68C)[2];
        d = dx;
        denom = -(*(s16 **)&D_8017F698)[2];
    } else {
        denom = (*(s16 **)&D_8017F698)[2];
        d = (*(s16 **)&D_8017F68C)[2] - (s16) arg2;
        dx = -d;
    }
    n = -d;
    {
        register s16 *b8 __asm__("$6") = *(s16 **)&D_8017F698;
        u16 *ac = *(u16 **)&D_8017F68C;
        b4 = D_8017F694;
        b4[0] = ac[0] + n * b8[0] / denom;
        b4[1] = ac[1] + n * b8[1] / denom;
        b4[2] = ac[2] + dx;
    }

    if (b4[0] < (*(  s16 * )((s8 *)( arg0 ) + (  4 ))) ) return 0;
    if ((*(  s16 * )((s8 *)( arg0 ) + (  6 )))  < b4[0]) return 0;
    if (b4[1] < (*(  s16 * )((s8 *)( arg0 ) + (  8 ))) ) return 0;
    if ((*(  s16 * )((s8 *)( arg0 ) + (  0xA )))  < b4[1]) return 0;
    if (a1v & 0x8000) {
        u16 *b0 = *(u16 **)&D_8017F690;
        b4[0] = b0[0];
        b4[1] = b0[1];
    }
    D_801152AA = 0;
    (*(s16 *)D_801152A8) = 0;
    if (a1v & 1) {
        D_8017F694[2] = a2v + 2;
        __asm__ __volatile__("");
        D_801152AC = 0xFFF;
    } else {
        D_801152AC = -0xFFF;
        D_8017F694[2] = a2v - 2;
    }
    __asm__ __volatile__("" :: "r"(a1v), "r"(a2v));
    (*(s16 *)D_80126720) = ((*(  s16 * )((s8 *)( arg0 ) + (  4 )))  + (*(  s16 * )((s8 *)( arg0 ) + (  6 ))) ) >> 1;
    D_80126722 = ((*(  s16 * )((s8 *)( arg0 ) + (  8 )))  + (*(  s16 * )((s8 *)( arg0 ) + (  0xA ))) ) >> 1;
    result = 1;
    D_80126724 = ((*(  s16 * )((s8 *)( arg0 ) + (  0xC )))  + (*(  s16 * )((s8 *)( arg0 ) + (  0xE ))) ) >> 1;
    return result;
}
