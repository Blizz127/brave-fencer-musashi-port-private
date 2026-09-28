/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1120 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012CBCC(s32 a0);
extern void func_8013C9C4(void *a0);
extern void func_801A2658(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32  func_8012BEE8(s32 a0);
extern void func_8012A8E8(void);
extern void func_801830D8(void *a0);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32  func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32  func_8012B70C(s16 *a0, s16 *a1);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern u16 D_80186F44[];
extern u8  D_801A68BC[];
extern u8  D_801A68F4[];
extern u8  D_800D3918[];
extern u8  D_801152A8[];
extern s32 D_80126B78[];

void func_801A1120(s32 arg0) {
    s32 buf[2];   /* sp+0x18 */
    s32 out[2];   /* sp+0x20 */
    u8 *d;
    s32 *tbl;

    switch (*(u16 *)(arg0 + 0x34)) {
    case 0:
        if (*(s32 *)(arg0 + 0x94) == 0x26) {
            *(s16 *)(arg0 + 0x98) = 0;
            *(u16 *)(arg0 + 0x34) += 1;
        }
        break;

    case 1:
        func_8012CBCC(arg0);
        if (*(s32 *)(arg0 + 0xD0) != 0) {
            *(u16 *)(*(s32 *)(*(s32 *)(arg0 + 0xD0) + 0x20) + 0x18) -= 0x12C;
            *(u16 *)(*(s32 *)(*(s32 *)(arg0 + 0xD0) + 0x20) + 0x1A) -= 0x12C;
        }
        if (*(s32 *)(arg0 + 0x14) >= 0) {
            *(s32 *)(arg0 + 0x1C) = 8;
            *(u16 *)(arg0 + 0x34) += 1;
        }
        break;

    case 2:
        if (func_8012BEE8(arg0) != 0) {
            ((void (*)(s32))func_8012A8E8)(arg0);
            *(u16 *)(arg0 + 0x34) += 1;
        }
        /* fallthrough */
    case 3:
        if (*(s32 *)(arg0 + 0xD0) != 0) {
            *(u16 *)(*(s32 *)(*(s32 *)(arg0 + 0xD0) + 0x20) + 0x18) += 0x12C;
            *(u16 *)(*(s32 *)(*(s32 *)(arg0 + 0xD0) + 0x20) + 0x1A) += 0x12C;
        }
        if (((s32 (*)(s32))func_8012CBCC)(arg0) & 0x2000) {
            func_801830D8((void *)arg0);
            func_8013C9C4(D_80186F44);
            func_801A2658(arg0, (s32)D_801A68BC);
            func_801A2658(arg0, (s32)(D_801A68BC + 8));
            func_8002D4C8(0xB52, 0);
            *(u16 *)(arg0 + 0x34) += 1;
        }
        d = D_800D3918;
        tbl = D_80126B78;
        func_8012F14C(tbl[0] + 0x34, (s32)d, (s32)buf);
        func_8012F14C(tbl[0] + 0x34, (s32)D_801A68F4, (s32)out);
        if (func_80135888(*(s32 *)(arg0 + 0x20), *(s32 *)(arg0 + 0x58), (s32)buf, (s32)out) != 0) {
            func_8012F568(1, 0x4002,
                          func_8012B70C((s16 *)d, (s16 *)D_801152A8),
                          0x1E, (s32)out, (s32)D_801152A8);
        }
        break;

    case 4:
        if (*(s16 *)(arg0 + 0x98) == 0) {
            *(s16 *)(arg0 + 2) = 0x13;
            *(s32 *)(arg0 + 0xE0) |= 0x10;
        }
        break;
    }
}
