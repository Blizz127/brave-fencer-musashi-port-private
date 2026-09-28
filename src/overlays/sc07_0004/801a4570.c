/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4570 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz, pad; } SV3_801A4570;
extern void func_8012BE54(s32 a0);
extern s32  func_8012B8A4(s16 *a0);
extern s32  func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern void func_801A9C00(void *a0);
extern s16  D_80126B5E;
extern s16  D_80126B62;
extern s16  D_80126B66;
extern s32 *D_80126B78;
extern s32 *D_80126B90;
extern u8   D_801152A8[];

void func_801A4570(void *arg0)
{
    SV3_801A4570 localA; /* sp+0x18 */
    SV3_801A4570 localB; /* sp+0x20 */
    s16 v0;

    v0 = *(s16 *)((u8 *)arg0 + 0xFE);
    if (v0 != 0) {
        *(s16 *)((u8 *)arg0 + 0xFE) = v0 - 1;
        return;
    }

    if (((s32 (*)(s32))func_8012BE54)((s32)arg0) >= 0x640) {
        return;
    }

    {
        u16 diff = (u16)D_80126B62 -
            (*(u16 *)((u8 *)arg0 + 0xA) + *(u16 *)((u8 *)arg0 + 0x52)) + 0x8F;
        if (diff >= 0xDF) {
            return;
        }
    }

    func_801A9C00(arg0);
    *(s16 *)((u8 *)arg0 + 0xFE) = 8;

    localA.vx = *(u16 *)((u8 *)arg0 + 0x6) + *(u16 *)((u8 *)arg0 + 0x50);
    localA.vy = *(u16 *)((u8 *)arg0 + 0xA) + *(u16 *)((u8 *)arg0 + 0x52) - 0x40;
    localA.vz = *(u16 *)((u8 *)arg0 + 0xE) + *(u16 *)((u8 *)arg0 + 0x54);

    localB.vx = (u16)D_80126B5E;
    localB.vy = (u16)D_80126B62 - 0x20;
    localB.vz = (u16)D_80126B66;

    if (func_80135888((s32)D_80126B78, (s32)D_80126B90, (s32)&localA, (s32)&localB) != 0) {
        s32 dist = func_8012B8A4((s16 *)arg0);
        func_8012F568(1, 4, dist, 0x40, (s32)&localB, (s32)D_801152A8);
    }
}
