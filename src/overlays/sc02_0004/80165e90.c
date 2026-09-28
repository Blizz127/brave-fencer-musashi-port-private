/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165E90 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern s32 *D_80126B78;
extern s32 D_80126B9C;
extern void func_801484B0(s32 a0, s32 a1);
extern void func_80148534(s32 a0, s32 a1);
extern void func_801484B0(s32, s32);
extern void func_80148534(s32, s32);
extern s32 func_80165FA4(s32 a0, s32 a1, s32 a2);
extern s32 func_80167DBC(s32 a0, s32 a1, s32 a2);
extern s32 func_80167AE0();

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
