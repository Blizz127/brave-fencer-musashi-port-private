/* SC02.CD FILE_031 / ov_SC02_031 retail span [801599A4,801599E0).
 * Offset 0x3184C at overlay base 80128158. SHA256(span)=6fca1cd1dc4b557f8cd34884f5ab47e2543ca89bdbba6b20343243223b757ee3.
 * STOP pc=801599a4 (func_801599A4), CPU_BOUNDARY/REFUSED, ra=8016ee78.
 * Callee from burned func_8016EE40 (jal 0C056669).
 * Donor shape: Druthulu shared/ov/func_801599A4.h (jump table D_8018730C[*a0]).
 * NOT MAIN10; NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_80159C84 / shared OV body.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801599A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801599A4(void *a0) {

    extern void (*D_8018730C[])(void *);
    D_8018730C[*(u16 *)((s32)a0 + 0x0)](a0);
}
