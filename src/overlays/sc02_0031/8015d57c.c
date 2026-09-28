/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015D57C,8015D5E8).
 * Offset 0x35424 at overlay base 80128158. SHA256(span)=607c1d03c4fb583e087a0c3b1bb143dd9cef9199c6d793f1ac87f45449690346.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015d57c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015D57C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80155440(s32 *a0);
extern void func_80146CA0(void *a0);
extern void func_801746DC(void);

void func_8015D57C(s32 arg0)
{
    s16 *p;
    func_80154150((s32)arg0, 0x19);
    func_801553A8(arg0);
    func_80155440(arg0);
    func_80146CA0(arg0);
    *(s32 *)((s8 *)arg0 + 0x234) = 0;
    p = *(s16 **)((s8 *)arg0 + 0x178);
    if (p != 0) {
        if (*(u16 *)p == 0x1F8) {
            *(s16 *)((s8 *)p + 0xFC) = 1;
            func_801746DC();
        }
    }
}
