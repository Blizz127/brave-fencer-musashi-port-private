/* SC02 resident image [80165E90,80165FA4) at overlay base 0x80128158.
 * SHA256(span)=a333e8cb00dfd8aa5c4395585cb5d118b4e81b4ec8c1666c334844ceec9cf00a.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165E90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801484B0(s32 a0, s32 a1);
extern s32 func_80165FA4(s32 a0, s32 a1, s32 a2);
extern s32 func_80167DBC(s32 a0, s32 a1, s32 a2);
extern void func_80148534(s32 a0, s32 a1);
extern s32 func_80167AE0();
extern s32 D_80126B9C;
extern s32 D_80126B58;
extern s32 *D_80126B78;

void func_80165E90(void) {
    s32 s1 = (s32)&D_80126B58;
    s32 buf1[2];
    s32 buf2[2];
    s32 v1;
    if ((D_80126B9C & 0x10000400) == 0x10000000) {
        v1 = (s32)D_80126B78;
        if (*(s32 *)(v1 + 0x4) >= 0) {
            if (*(s32 *)(v1 + 0x20) != 0) {
                func_801484B0((s32)buf1, (s32)buf2);
                func_80165FA4(s1, (s32)buf1, (s32)buf2);
                func_80167DBC(s1, (s32)buf1, (s32)buf2);
            }
        }
    }
    if ((*(s32 *)(s1 + 0x44) & 0x20020400) == 0x20000000) {
        v1 = *(s32 *)(s1 + 0x20);
        if (*(s32 *)(v1 + 0x4) >= 0) {
            if (*(s32 *)(v1 + 0x20) != 0) {
                func_80148534((s32)buf1, (s32)buf2);
                func_80165FA4(s1, (s32)buf1, (s32)buf2);
                func_80167AE0(s1, (s32)buf1, (s32)buf2);
            }
        }
    }
}
