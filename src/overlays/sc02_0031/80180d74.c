/* SC02.CD FILE_031 / ov_SC02_031 retail span [80180D74,80180DB0).
 * Offset 0x58C1C at overlay base 80128158. SHA256(span)=eca967123bd6e741a896e82078097c0093481762f23ac353ec15084c986fb823.
 * STOP callback via *(s0+0xC) from MAIN10 func_800D1984 jalr — NOT MAIN10 800D19DC.
 * Donor shape: Druthulu ov_SC02_031_jr_8017AE2C func_80180D74 (jump table D_80188D6C).
 * NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text in jr_8017AE2C.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80180D74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188D6C[])(void *);

void func_80180D74(void *a0) {
    D_80188D6C[*(u8 *)((s32)a0 + 0x15)](a0);
}
