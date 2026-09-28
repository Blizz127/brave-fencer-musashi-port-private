/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A079C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_8005C49C(void);
extern s32  func_8012BA10(s32 a0, s32 a1);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_801A2658(s32 a0, s32 a1);
extern void func_8013C9C4(void *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_8012ADE4(u8 *a0);
extern void func_801A24E8(s32 a0);
extern void func_8012BD14(s32 a0);
extern s32  func_8012BDBC(s32 a0, s32 a1);
extern s32  func_8012BEE8(s32 a0);
extern u8 D_80186F68[];
extern u8 D_801A68BC[];
extern u8 D_801A68C4[];

void func_801A079C(s32 arg0) {
    s32 s1;
    s32 unused[2];   /* LOAD-BEARING: buys the target's 0x28 frame (lever 3) */
    s32 v1;

    *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12) += func_8012BA10(arg0, 0x20);
    func_8012B178(arg0, 0xFFFB0000);

    v1 = *(s32 *)(arg0 + 0x94);
    if (v1 == 0xF) {
        func_801A2658(arg0, (s32)D_801A68BC);
        func_8013C9C4(D_80186F68);
        func_8002D4C8(0xB53, 0);
    } else if (v1 == 0x35) {
        func_801A2658(arg0, (s32)D_801A68C4);
        func_8013C9C4(D_80186F68);
        func_8002D4C8(0xB53, 0);
    }

    if ((((s32 (*)(s32))func_8012CBA4)(arg0) & 0x2000) == 0) {
        func_8012ADE4((u8 *)arg0);
    }
    func_801A24E8(arg0);

    if (*(s32 *)(arg0 + 0xE8) > 0xFFFF) {
        if (func_8005C49C() & 1) {
            *(s16 *)(arg0 + 2) = 0xD;
        } else {
            *(s16 *)(arg0 + 2) = 0xB;
        }
        return;
    }

    s1 = ((s32 (*)(s32))func_8012BD14)(arg0);
    if (s1 <= 0x10000) {
        *(s16 *)(arg0 + 2) = 0xF;
        return;
    }
    if (s1 <= 0x24000) {
        if (func_8012BDBC(arg0, 0x180) != 0) {
            *(s16 *)(arg0 + 2) = 0x11;
            return;
        }
    } else if (s1 > 0xC4000 && *(s32 *)(arg0 + 0x94) == 0x4E) {
        *(s16 *)(arg0 + 2) = 9;
        return;
    }
    if (func_8012BEE8(arg0) != 0) {
        if (s1 <= 0x64000) {
            *(s16 *)(arg0 + 2) = 0xF;
        } else {
            *(s32 *)(arg0 + 0x1C) = 0x80;
        }
    }
}
