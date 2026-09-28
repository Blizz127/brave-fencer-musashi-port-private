/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB2AC - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixY func_8004A0DC
extern u8 D_80078EC1;
void func_80146C3C(void *);
typedef struct { s32 w[8]; } Blk20;

void func_800CB2AC(void *a0)
{
    extern u8 D_80078EC1;
    extern u16 D_800CB4B4[];
    extern Blk20 D_800AE620;
    extern s16 D_80126B5E;
    extern s16 D_80126B62;
    extern s16 D_80126B66;
    extern void RotMatrixY(s32, void *);
    extern void func_8012F14C(s32, s32, s32);
    extern void func_80146C3C();

    u8 *s1;
    u8 *p;
    struct { s16 x, y, z; } vec;
    Blk20 m;
    u32 t;

    s1 = (u8 *)a0;
    p = *(u8 **)(s1 + 0x20);
    if (D_80078EC1 == 0x14) {
        *(u32 *)(s1 + 0x2C) += 4;
        if (*(u32 *)(s1 + 0x2C) < 0x1C1) {
            t = (*(u32 *)(s1 + 0x1C))++;
            *(u16 *)(p + 0x18) = *(u16 *)(p + 0x1A) = D_800CB4B4[t & 3];
            *(u32 *)(s1 + 0x30) += 0xA00000 / (*(u32 *)(s1 + 0x2C) * 804);
            m = D_800AE620;
            RotMatrixY(*(u32 *)(s1 + 0x30), &m);
            vec.x = 0;
            vec.y = -*(volatile u32 *)(s1 + 0x2C);
            t = *(volatile u32 *)(s1 + 0x2C);
            m.w[5] = D_80126B5E;
            m.w[6] = D_80126B62 - 0x1C;
            m.w[7] = D_80126B66;
            vec.z = t - (t >> 2);
            func_8012F14C((s32)&m, (s32)&vec, (s32)&vec);
            *(u16 *)(s1 + 6) = vec.x;
            *(u16 *)(s1 + 0xA) = vec.y;
            *(u16 *)(s1 + 0xE) = vec.z;
            return;
        }
    }
    func_80146C3C(s1);
}
