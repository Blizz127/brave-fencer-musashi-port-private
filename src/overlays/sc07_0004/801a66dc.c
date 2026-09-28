/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A66DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001C924(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern void func_801A39D0(s32 a0);
extern void func_80132288(s32 *a0, s32 *a1, s32 a2);
extern s32 func_801A8528(s32 a0);
extern void func_801A85A8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801A8A64(s32 a0);
extern void func_8017FA74(void);
extern void func_8013240C(s32 a0);
extern void func_801A18F4(s32 a0);
extern s32 D_801BF01C;
extern s32 *D_801AFB78;
extern s32 D_801F8724;
extern s32 D_801F8730;
extern u16 D_8019FF8A;

void func_801A66DC(s32 a0) {
    s32 *sp;
    u8 pad[8];

    switch (*(u16 *)(a0 + 0x34)) {
    case 0:
        sp = &D_801BF01C;
        func_8001C924(*(s32 *)(a0 + 0x20), sp);
        func_8012B2CC(a0);
        func_801A39D0(a0);
        func_80132288(&D_801F8724, D_801AFB78, *sp);
        D_8019FF8A |= 1;
        *(s32 *)(a0 + 0xD4) = func_801A8528(a0);
        func_801A85A8(a0, 0x28080A0, 0, 0x200);
        func_801A8A64(a0);
        func_8017FA74();
        *(u16 *)(a0 + 0x34) += 1;
        break;
    case 1:
        func_8013240C((s32)&D_801F8724);
        if (D_801F8730 & 0x4000) {
            func_801A18F4(a0);
        }
        break;
    }
}
