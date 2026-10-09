/* SC02.CD FILE_031 / ov_SC02_031 retail span [801708B0,80170928).
 * Offset 0x48758 at overlay base 80128158. SHA256(span)=4806d9c5010fb51228f2a2a7f15594524ffa8acfe9f83ccffccff087ac84adbe.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801708b0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801708B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801484B0(s32 a0, s32 a1);
extern void func_80149350(s32 arg0, s32 a1, s32 a2);
extern s32 func_8014C168(s32*, s32);
extern void func_80171928(void *a0);

void func_801708B0(void* a0)
{
    extern void *D_8011F738;
    u16 sp10[4];
    u16 sp18[4];
    short *r;
    func_801484B0((s32)&sp10, (s32)&sp18);
    ((void (*)(s32, void *, void *))func_80149350)((s32)a0, &sp10, &sp10);
    r = (short *)((s32 (*)(s32, s32))func_8014C168)((s32)a0, (*(s32 *)&D_8011F738));
    r[3] = sp10[0];
    r[5] = sp10[1];
    r[7] = sp10[2];
    func_80171928((void *)a0);
}
