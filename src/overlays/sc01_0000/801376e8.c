/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801376E8 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_80139BE0(s32 a0);
void *aF801376E8(int a0, int a1) __asm__("func_801376E8");
void * aF801376E8(int a0, int a1) __asm__("func_801376E8");

void *aF801376E8(int a0, int a1)
{
    extern s32 D_801269F0;
    extern u8 D_801269FD;
    extern u16 D_80126A14[];
    extern s16 D_80126A1C;
    extern s16 D_80126A20;
    extern s16 D_80126A22;
    extern s16 D_80126A24;
    extern u16 D_80126A26;
    u16 *p = (u16 *)a1;
    s32 obj = (s32)&D_801269F0;
    func_801377B4(a0, 0x6200, obj);
    D_80126A1C = 0x1C;
    D_801269FD = 0;
    if (p != 0) {
        D_80126A14[0] = p[0];
        D_80126A14[1] = p[1];
    }
    func_80139BE0(obj);
    D_80126A20 = (D_80126A14[0] + 0x28) - ((D_80126A24 + 0x28) >> 1);
    D_80126A22 = D_80126A14[1] - ((s16)D_80126A26 >> 1);
    return (void *)obj;
}
