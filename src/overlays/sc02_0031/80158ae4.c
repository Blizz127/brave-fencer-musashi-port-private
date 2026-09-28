/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158AE4,80158BB0).
 * Offset 0x3098C at overlay base 80128158. SHA256(span)=f33a1be301e37b59a4f9010babb080c4201d5dfe6c8b129dc4a6d8c4a7d401d4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80158ae4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158AE4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800AE6AC;
extern s32 D_800AE6B0;
extern s32 D_80078EC8;
extern void func_8016F264(void);
extern void func_80165840(void);
extern void func_801658DC(void);
extern s32 func_80165A20(s32 a0);
extern void func_80165A78(s32);
extern void func_8014BF48(void);
extern void func_8014CBF8(void *a0);
extern void func_8014B160(s32 a0);
extern void func_80149020(s32 *a0);
extern void func_80146CA0(void *a0);

void func_80158AE4(void * a0)
{
    D_800AE6B0 = D_800AE6AC | 0x1000000;
    func_8016F264();
    ((void (*)(s32))func_80165840)(a0);
    ((void (*)(s32))func_801658DC)(a0);
    func_80165A20(a0);
    func_80165A78(a0);
    func_8014BF48();
    func_8014CBF8((void *)a0);
    func_8014B160(a0);
    func_80149020((s32 *)a0);
    *(s16 *)(a0 + 0x12E) = 0;
    *(s16 *)(a0 + 0x74) = 0x1000;
    *(s16 *)(a0 + 0x72) = 0x1000;
    *(s16 *)(a0 + 0x70) = 0x1000;
    *(s16 *)(a0 + 0x6C) = 0x1000;
    *(s16 *)(a0 + 0x6A) = 0x1000;
    *(s16 *)(a0 + 0x68) = 0x1000;
    *(s16 *)(a0 + 0x64) = 0x1000;
    *(s16 *)(a0 + 0x62) = 0x1000;
    *(s16 *)(a0 + 0x60) = 0x1000;
    *(s16 *)(a0 + 0x1BA) = 0x1000;
    *(s16 *)(a0 + 0x1B8) = 0x1000;
    *(s16 *)(a0 + 0xF6) = 0x1000;
    D_80078EC8 = 0;
    *(s16 *)(a0 + 0x1C8) = 0;
    func_80146CA0((void *)a0);
}
