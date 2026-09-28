/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A09C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_8012BA10(s32 a0, s32 a1);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_8012ADE4(u8 *a0);
extern void func_801A2658(s32 a0, s32 a1);
extern void func_8013C9C4(void *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32  func_8012BEE8(s32 a0);
extern void func_8012BE54(s32 a0);
extern s32  func_8012BDBC(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_801A27A4(void *a0, void *a1);
extern s32  func_801A19C8(s32 a0);
extern s32  func_80153BD8(s32 a0);
extern void func_801A1924(s32 a0);
extern void func_80153C44(s32 a0, s32 a1, s16 a2);
extern void func_801A24E8(s32 a0);
extern u8   D_801A68BC[];
extern u8   D_801A68C4[];
extern u8   D_80186F68[];
extern u8   D_801F1198[];
extern u8   D_801F1340[];
extern u8   D_801F1238[];
extern u16  D_800B99DA;

void func_801A09C8(s32 arg0) {
    volatile s32 pad[10];
    s32 t;
    s32 q;

    switch (*(u16 *)(arg0 + 0x34)) {
    case 0:
        t = func_8012BA10(arg0, 0x10);
        *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12) += t;
        func_8012B178(arg0, -0xF0000);
        if ((((s32 (*)(s32))func_8012CBA4)(arg0) & 0x2000) == 0) {
            func_8012ADE4((u8 *)arg0);
        }
        q = *(s32 *)(arg0 + 0x94);
        if (q == 9) {
            func_801A2658(arg0, (s32)D_801A68BC);
            func_8013C9C4(D_80186F68);
            func_8002D4C8(0xB53, 0);
        } else if (q == 0x1A) {
            func_801A2658(arg0, (s32)D_801A68C4);
            func_8013C9C4(D_80186F68);
            func_8002D4C8(0xB53, 0);
        }
        if (func_8012BEE8(arg0) == 0) {
            if (((s32 (*)(s32))func_8012BE54)(arg0) > 0x40000) {
                break;
            }
        }
        if (func_8012BDBC(arg0, 0x200) == 0) {
            break;
        }
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        func_8012A828(arg0, D_801F1198);
        *(s32 *)(arg0 + 0x1C) = 0x30;
        *(s32 *)(arg0 + 0x10) = *(s32 *)(arg0 + 0x10) * 2;
        *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x18) * 2;
        func_8002D4C8(0xB79, 0);
        break;

    case 1:
        *(s32 *)(arg0 + 0x10) = *(s32 *)(arg0 + 0x10) * 15 / 16;
        *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x18) * 15 / 16;
        if (D_800B99DA % 3 == 0) {
            func_801A27A4((void *)arg0, D_801A68BC);
            func_801A27A4((void *)arg0, D_801A68BC + 8);
        }
        if ((((s32 (*)(s32))func_8012CBA4)(arg0) & 0x2000) == 0) {
            func_8012ADE4((u8 *)arg0);
        }
        if (func_801A19C8(arg0) == 1) {
            *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
            *(s32 *)(arg0 + 0xE0) |= 0x40;
            break;
        }
        if (func_8012BEE8(arg0) == 0) {
            break;
        }
        goto state5;

    case 2:
        if (func_80153BD8(arg0) != 0) {
            *(s32 *)(arg0 + 0xE0) |= 8;
            *(u16 *)(arg0 + 0x5C) &= ~0x800;
        } else {
            *(s32 *)(arg0 + 0xE0) &= ~0x40;
        }
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        /* fallthrough */
    case 3:
        if (*(s32 *)(arg0 + 0xE0) & 8) {
            func_801A1924(arg0);
        }
        if (*(s16 *)(arg0 + 0x98) != 0) {
            break;
        }
        if (*(s32 *)(arg0 + 0xE0) & 8) {
            func_8012A828(arg0, D_801F1340);
            *(u16 *)(arg0 + 0x34) = 4;
            break;
        }
    state5:
        func_8012A828(arg0, D_801F1238);
        *(u16 *)(arg0 + 0x34) = 5;
        break;

    case 4:
        if (*(s32 *)(arg0 + 0x94) < 0x86) {
            func_801A1924(arg0);
        }
        q = *(s32 *)(arg0 + 0x94);
        if (q == 0x3E) {
            func_8002D4C8(0xC18, 0);
            q = *(s32 *)(arg0 + 0x94);
        }
        if (q == 0x86) {
            func_80153C44(1, 0x50, *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12));
            func_8002D4C8(0xC17, 0);
            func_8002D4C8(0xC7B, 0);
        }
        /* fallthrough */
    case 5:
        if (*(s16 *)(arg0 + 0x98) == 0) {
            *(s16 *)(arg0 + 2) = 3;
            *(u16 *)(arg0 + 0x5C) |= 0x800;
            *(s32 *)(arg0 + 0xE0) &= ~0x40;
        }
        break;
    }

    func_801A24E8(arg0);
}
