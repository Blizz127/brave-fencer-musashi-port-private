/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B1B4,8012B200).
 * Offset 0x305C at overlay base 80128158. SHA256(span)=0bfac1bc003dd13ab61f9ba8cdb74f43f471aab93ea5cc65ec9a00db2e1b4aba.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b1b4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B1B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_8012B1B4(s32 a0, s32 a1) {
    s32 sp10[4];
    func_800484EC(*(s32 *)(a0 + 0x20) + 0x34, a1, (s32)sp10);
    *(s32 *)(a0 + 0x10) = sp10[0];
    *(s32 *)(a0 + 0x18) = sp10[2];
}
