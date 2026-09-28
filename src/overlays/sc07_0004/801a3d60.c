/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3D60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx32_801A3D60;
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_8012BE54(s32 a0);
extern s32 func_8012B8A4(s16 *a0);
extern s32 func_8017267C(s32 *a0);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 D_801F8864;
extern s32 D_80126B58[4];
extern s32 D_80126B5C;
extern s32 D_80126B64;

void func_801A3D60(s32 a0)
{
    /* D_800AE620 is the shared 32-byte matrix global; this TU's real file-scope
     * spelling (`extern Mtx32_801A90D8 D_800AE620;`) is declared LATER in the
     * file. A second file-scope spelling here is a hard `conflicting types`
     * error in gcc-2.7.2 (see func_801A3180 / func_801A3B18 above it), so this
     * copy is BLOCK scope, matching this TU's own house style. */
    extern s32 D_800AE620[8];
    Mtx32_801A3D60 m;   /* sp+0x10 */
    s32 buf[3];         /* sp+0x30 */
    s32 s0;
    s32 *s1;
    s32 r;

    s0 = a0;
    m = *(Mtx32_801A3D60 *)&D_800AE620;
    s1 = (s32 *)&m;

    if (D_801F8864 <= 0xAFFFF) {
        D_801F8864 = D_801F8864 + 0x4000;
    }

    r = ((s32 (*)(s32))func_8012BE54)(s0);
    func_8004A0DC((s16)func_8012B8A4((s16 *)s0), s1);
    s0 = r;

    if (D_801F8864 != 0 && s0 >= 0x101) {
        if (func_8017267C(D_80126B58) == 0) {
            buf[1] = 0;
            buf[0] = 0;
            buf[2] = D_801F8864;
            func_800484EC((s32)s1, (s32)buf, (s32)buf);
            D_80126B5C += buf[0];
            D_80126B64 += buf[2];
        }
    }
}
