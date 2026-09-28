/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE514 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 func_8012C1B8(void);
extern void func_8001C214(s32, s32);
extern void func_8012A828(s32, s32);
extern void func_8012CAE4(void *);
extern void func_8012E8E0(s32, s32);
extern void func_80178B18(s32, s32);

void func_801EE514(void *a0) {
    extern s32 D_801F5964;
    extern s32 D_801BA404;
    extern s32 D_801EE670;
    extern s32 D_801EE6A0;
    extern s32 D_801F5998;
    extern s32 D_801F5994;
    s32 v0;
    s32 ptr;

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
    } else {
        func_8001C214(v0, (s32)&D_801F5964);
        ptr = *(s32 *)((s32)a0 + 0x68);
        *(s32 *)&D_801F5998 = 0;
        *(s16 *)(ptr + 0xC) = 0x7FFF;
        *(s16 *)((s32)a0 + 0x2) = 1;
        func_8012A828((s32)a0, (s32)&D_801BA404);
        func_8012E8E0((s32)a0, (s32)&D_801EE670);
        *(s16 *)((s32)a0 + 0x34) = 0;
        func_80178B18((s32)a0, (s32)&D_801EE6A0);
        v0 = func_80029504();
        *(s32 *)&D_801F5994 = v0;
    }
}
