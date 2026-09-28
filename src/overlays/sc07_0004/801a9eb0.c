/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A9EB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012AD80(s32 a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 func_8017D7D4(void *a0, void *a1, void *a2, s32 a3);
extern void func_801AA004(void *a0, void *a1);
extern void func_801AA210(void *a0, void *a1, void *a2);
extern s32 D_801B077C;

void func_801A9EB0(void *arg0) {
    void *s2;
    s8 sp10[0x20];
    s8 sp30[0x18];

    func_801AA004(arg0, sp10);
    func_8012AD80((s32)arg0);
    func_8012AD80((s32)arg0);
    func_801AA210(arg0, sp10, sp30);
    s2 = &D_801B077C;
    *(s32 *)((u8 *)arg0 + 0xCC) = func_8017D7D4(sp30, sp30 + 8, s2, 12);
    *(s32 *)((u8 *)arg0 + 0xD0) = func_8017D7D4(sp30, sp30 + 0x10, s2, 12);
    *(s32 *)((u8 *)arg0 + 0x1C) = 0x30;
    func_8012AD44((s32 *)arg0, 1);
}
