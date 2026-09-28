/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A19C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct M4_801A0168 {
    u8 unk0[4];
} M4_801A0168;
extern M4_801A0168 D_801A0168;
extern u16 D_8019FF8A;
extern void func_801A370C(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_801A85A8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801AAA6C(s32 a0);
extern void func_80184C70(void);
extern void func_80184DB0(s32 a0, void *a1, s32 a2);
extern void func_801A3B08(s32 a0);
extern void func_801A3EEC(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_801A395C(s32 a0, s32 a1);
extern void func_801A1C38(s32 a0);
extern s32 func_801A861C(s32 a0, s16 a1);
extern void func_801A8DCC(s32 a0, s32 a1);
extern void func_80184E20(void *a0);
extern void func_80184E98(s32 a0, s32 a1);
extern void func_801A3D60(s32 a0);
extern void func_801A3EA8(s32 a0);
extern void func_8018503C(void);
extern int func_8005C49C(void);

void func_801A19C0(s32 a0) {
    M4_801A0168 sp10;

    sp10 = D_801A0168;
    func_801A370C(a0);
    switch (*(u16 *)(a0 + 0x34)) {
    case 0:
        if (func_8012BEE8(a0) != 0) {
            func_801A85A8(a0, 0x1600000, 0, 0x300);
            *(s32 *)(a0 + 0x1C) = 0x10;
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
        }
        break;
    case 1:
        if (func_8012BEE8(a0) != 0) {
            func_801A85A8(a0, 0x1600000, 1, 0x300);
            *(s32 *)(a0 + 0x1C) = 0x18;
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
        }
        break;
    case 2:
        if (func_8012BEE8(a0) != 0) {
            *(s32 *)(a0 + 0x1C) = 0x80;
            *(u16 *)(a0 + 0x100) = 0;
            func_80184C70();
            func_80184DB0(0, &sp10, -8);
            *(u16 *)(a0 + 0xE4) = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
            func_801A3B08(a0);
            func_801A3EEC(9);
            func_8002D4C8(0xB5A, 0);
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
        } else {
            func_801AAA6C(a0);
        }
        break;
    case 3:
        func_801A395C(a0, -0x230);
        if (func_8012BEE8(a0) != 0) {
            D_8019FF8A &= 0xFFFE;
            func_801A1C38(a0);
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) = *(u16 *)(a0 + 0xE4);
            func_801A3EEC(1);
            func_8002D4C8(4, 0xB5A);
        } else {
            if ((*(s32 *)(a0 + 0x1C) & 0xF) == 0) {
                if (func_801A861C(a0, *(s16 *)(a0 + 0x100)) != 0) {
                    *(u16 *)(a0 + 0x100) = *(u16 *)(a0 + 0x100) + 1;
                    func_8002D4C8(0xB59, 0);
                }
            }
            if ((u32)(*(s32 *)(a0 + 0x1C) - 0x19) < 0x57) {
                func_801A8DCC(a0, 0);
                func_80184E20((void *)(a0 + 4));
                func_80184E98(func_8005C49C() & 0xFF8, 0x60);
                ((void (*)())func_801A3D60)(a0);
            }
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) += 0x80;
            func_801A3EA8(a0);
        }
        func_8018503C();
        break;
    }
}
