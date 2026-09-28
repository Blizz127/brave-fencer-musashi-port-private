/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801830EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C194(void);
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);

s32 func_801830EC(s32 a0, s32 a1, s16 a2, s16 a3, s32 a4) {
    s32 obj;

    obj = func_8012C194();
    if (obj == 0) {
        return 0;
    }
    func_8001CB6C((u8 *)obj, a1, a2, a3);
    *(u16 *)(obj + 0x10) = 0xC00;
    *(u8 *)(obj + 0x27) = a4;
    *(u16 *)(obj + 0x1A) = 0x2D00;
    *(u16 *)(obj + 0x18) = 0x2D00;
    *(u16 *)(obj + 8) = *(u16 *)(a0 + 6);
    *(u16 *)(obj + 0xA) = *(u16 *)(a0 + 0xA);
    *(u16 *)(obj + 0xC) = *(u16 *)(a0 + 0xE);
    return obj;
}
