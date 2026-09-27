/* Overlay range [80163534,80163664) from MAIN.CD member 0012.
 * SHA256(span)=73882b68a2fca6287a4ef885f5bcda8277a3147df7bea8798a1d891df6af51c1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80163664(s32, s32, s16 *, s16 *, void *, void *, void *, void *, s32, s32, void *, void *); /* static */
extern s32 *D_80114EB0;
extern s32 *D_80114EC8;
extern s32 *D_80115100;
extern s32 D_80115200;
extern s32 D_80115204;
extern s32 D_80115208;
extern s32 *D_80115298;
extern s32 *D_8011DAF0;
extern s32 *D_80126734;
extern s16 D_80126B18;
extern s16 D_80126B1A;
extern s16 D_80126B1C;
extern s16 D_801270B0;
extern s16 D_801270B2;
extern s16 D_801270B4;

void func_80163534(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4, void *arg5) {
    D_80115200 = 0;
    D_80115204 = 0;
    D_80115208 = 0;
    D_801270B0 = M2C_FIELD(arg0, u16 *, 0x44) + M2C_FIELD(arg5, u16 *, 0);
    D_801270B2 = M2C_FIELD(arg0, u16 *, 0x46) + M2C_FIELD(arg5, u16 *, 2);
    D_801270B4 = M2C_FIELD(arg0, u16 *, 0x48) + M2C_FIELD(arg5, u16 *, 4);
    D_80126B18 = M2C_FIELD(arg0, u16 *, 6) + M2C_FIELD(arg5, u16 *, 0);
    D_80126B1A = M2C_FIELD(arg0, u16 *, 0xA) + M2C_FIELD(arg5, u16 *, 2);
    D_80126B1C = M2C_FIELD(arg0, u16 *, 0xE) + M2C_FIELD(arg5, u16 *, 4);
    D_80115200 = func_80163664(arg1 & 0xFFFF, arg2 & 0xFFFF, &D_801270B0, &D_80126B18, &D_80114EB0, &D_80114EC8, &D_80115100, &D_8011DAF0, arg3, (s32) arg4, &D_80115298, &D_80126734);
}
