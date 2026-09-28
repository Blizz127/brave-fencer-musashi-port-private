/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D05B4 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s8 D_800D52BC[];
extern u8 D_800AF630[];
extern s16 D_800EC894;
extern void func_80015310(void);
extern void func_8001C044(void);
extern void func_800118AC(void);
extern void func_800183E0(s32 a0);

void func_800D05B4(void) {

    extern s32 D_800D4E6C;
    extern u32 D_800EC890;
    extern u32 D_800EC8A0;
    extern s32 D_800EC88C;
    int sp20;
    int sp1c;
    int sp18;
    int sp14;
    register u8 *s0 = D_800AF630;
    (void)sp20;
    (void)sp1c;
    (void)sp18;
    (void)sp14;
    func_8001C044();
    func_80015310();
    *(s0 + 0xA3E1) = 0;
    D_800EC890 = 0;
    D_800EC8A0 = 1;
    func_800183E0((s32)&D_800D4E6C);
    func_800183E0((s32)&D_800D52BC);
    (*(u16 *)&D_800EC894) = 0;
    (*(u32 *)&D_800EC88C) = -1;
    *(u16 *)(s0 + 0xA3B8) = 0;
    func_800118AC();
}
