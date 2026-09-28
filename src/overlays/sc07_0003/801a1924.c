/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1924 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
} Vec8_801A1924;
extern u8  D_801A68FC[];
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 D_80126B78[];
extern void func_8012EC04(s32 a0, s32 a1, s32 *a2);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32  func_8012B70C(s16 *a0, s16 *a1);

void func_801A1924(s32 arg0) {
    s32 sp10[8];                /* 0x10 */
    Vec8_801A1924 sp30;         /* 0x30 */
    u16 sp38[4];                /* 0x38 */

    func_8012EC04(arg0, 0x10, sp10);
    func_8012F14C((s32)sp10, (s32)D_801A68FC, (s32)&sp30);
    func_8012F14C((s32)sp10, (s32)(D_801A68FC + 8), (s32)sp38);
    D_80126B5E = sp30.a;
    D_80126B62 = sp30.b;
    D_80126B66 = sp30.c;
    *(s16 *)(*(s32 *)D_80126B78 + 0x12) = func_8012B70C((s16 *)sp38, (s16 *)&sp30);
}
