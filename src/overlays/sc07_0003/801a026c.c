/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A026C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_8005C49C(void);
extern s32  func_80029504(void);
extern void func_8012CAE4(void *);
extern s32  func_8012C354(s32, s32);
extern void func_8001D0E8(s32, s32, s32);
extern void func_8012A828(s32, void *);
extern void func_8012B2CC(s32);
extern void func_8012E8A8(u8 *);
extern s32  func_8012C588(s32, s32);
extern s32  func_8012C658(s32, s32, s32);
extern void func_8001C97C(s32 *);
extern void func_801A2E20(void);
extern u8  D_801A6874[];
extern u8  D_801A6854[];
extern u8  D_801F0008[];
extern u8  D_801A68A8[];
extern s32 D_801F4360[];
extern s32 D_801AE21C[];
extern s32 D_801AE228[];
extern s32 D_801F436C[];
typedef struct {
    /* 0x0 */ s16 a;
    /* 0x2 */ s16 b;
    /* 0x4 */ s32 c;
} Rec8_801A026C;
extern Rec8_801A026C D_801F1344[];
extern Rec8_801A026C D_801F1A5C[];
extern s32 D_801F4358;
extern s32 D_801F43B4;
extern s32 D_801F43B8;
extern s32 D_801F43BC;
extern u16 D_801F43C0;

void func_801A026C(s32 arg0)
{
    s32 i;
    s32 j;
    s32 k;

    if ((u32)func_80029504() >= 0x640) {
        func_8012CAE4((void *)arg0);
        return;
    }

    if (func_8012C354(arg0, (s32)D_801A6874) == 0) {
        return;
    }

    func_8001D0E8(*(s32 *)(arg0 + 0x20), 0x7FFF, 0x7FFF);

    *(s32 *)(arg0 + 0x58) = (s32)((u32)D_801A6854 | 0x10000000 | 0x40000000);
    func_8012A828(arg0, (void *)D_801F0008);

    *(s16 *)(arg0 + 0x02) = 1;
    *(s32 *)(arg0 + 0x48) = 0x30000;
    *(s32 *)(arg0 + 0x08) += 0xFD8A0000;
    func_8012B2CC(arg0);
    func_8012E8A8((u8 *)arg0);

    *(s16 *)(arg0 + 0xAE) = -1;
    *(s8 *)(arg0 + 0x75) = 2;
    *(s16 *)(arg0 + 0x76) = *(u16 *)(*(s32 *)(arg0 + 0x78));
    *(s32 *)(arg0 + 0xE4) = 0x50;
    *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x2C) |= 0x80;
    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x80) = (s32)D_801A68A8;

    *(s32 *)(arg0 + 0xCC) = func_8012C588(0x34C, arg0);
    *(s32 *)(arg0 + 0xD0) = func_8012C588(0x351, arg0);
    *(s32 *)(arg0 + 0xD4) = func_8012C658(0x34C, 2, arg0);
    *(s32 *)(arg0 + 0xD8) = func_8012C588(0x3AB, arg0);

    for (i = 0; i < 3; i++) {
        D_801F4360[i] = func_8005C49C() & 0x7FFF;
    }

    for (i = 62; i < 113; i++) {
        D_801F1344[i].a = 2;
    }

    for (i = 52; i < 140; i++) {
        D_801F1A5C[i].a = 2;
    }

    i = 0;
    k = 0;
    j = 0;
    for (; i < 20; i++) {
        if ((i != 0) && (i != 3)) {
            *(s32 *)((u8 *)D_801F436C + j) = *(s32 *)((u8 *)D_801AE21C + k);
            j += 4;
        }
        k += 4;
    }

    func_8001C97C(D_801F436C);

    D_801F43BC = 0;
    D_801F4358 = 0;
    D_801F43C0 = 3;
    D_801F43B4 = D_801AE228[0];
    D_801F43B8 = D_801AE21C[0];

    func_801A2E20();
}
