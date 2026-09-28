/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017EA20 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 rand(void);
extern int rand(void);
extern void func_8012B2CC(s32 a0);
extern void func_8012B2CC(s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8012AD50(void *arg0);
extern void func_8001C214(s32 a0, s32 a1);
extern s32  func_8012AD50(void *a0);
extern s32 D_8019E298;
extern u8  D_8019B5B4[][16];
extern s32 D_8019B5C0[][4];
extern s16 D_8019B5E6[][4];
extern u8  D_8019B624[];

void func_8017EA20(s32 param_1) {
    s32 obj;
    s32 n;

     


    obj = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(param_1 + 0x20) = obj;
    if (obj == 0) {
        func_8012CAE4((void *)param_1);
        return;
    }
    func_8001C214(obj, (s32)&D_8019E298);

    n = *(u16 *)(param_1 + 0x70) & 0xF;
    *(s16 *)(param_1 + 0x102) = n;
    if (n != 0) {
         
        s32 r = rand() & 0xFF;
        s32 h = D_8019B5C0[*(s16 *)(param_1 + 0x102)][0];
        s32 o;
         
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x2C) =
            *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x2C) | 0x10;
         
        o = *(s32 *)(param_1 + 0x20);
        *(s16 *)(o + 0x1C) = h + r;
        *(s16 *)(o + 0x1A) = h + r;
        *(s16 *)(o + 0x18) = h + r;
    }

    *(s32 *)(param_1 + 0x48) = 0x18000;
    *(s16 *)(param_1 + 0x100) = 0x1000 / D_8019B5E6[*(s16 *)(param_1 + 0x102)][0];

    {
        s32 t = *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x18);
         
        if (t >= 0x1000) {
            *(s16 *)(param_1 + 0x100) = 0x40;
        } else {
            *(s16 *)(param_1 + 0x100) = (0x1400 - t) >> 4;
        }
    }

     
    if (*(s16 *)(param_1 + 0x102) != 2) {
        s32 r = rand() & 0xFF;
        *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x12) =
            *(u16 *)(*(s32 *)(*(s32 *)(param_1 + 0x64) + 0x20) + 0x12) + r - 0x80;
    } else {
        s32 r = rand() & 1;
        *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x12) =
            *(u16 *)(*(s32 *)(*(s32 *)(param_1 + 0x64) + 0x20) + 0x12) + r * 0x1C0 - 0xE0;
    }

    func_8012B2CC(param_1);
    func_800484EC(*(s32 *)(param_1 + 0x20) + 0x34,
                  (s32)D_8019B5B4[*(s16 *)(param_1 + 0x102)],
                  param_1 + 0x10);

    {
        s32 r = rand();
        *(s32 *)(param_1 + 0x58) = ((u32)D_8019B624 | 0x20000000) | 0x40000000;
        *(u16 *)(param_1 + 0x5C) = 0xC000;
        *(u8 *)(param_1 + 0x75) = 0;
        *(s16 *)(param_1 + 0xE) = *(u16 *)(param_1 + 0xE) - (r & 0x1F);
    }
    func_8012AD50((void *)param_1);
}
