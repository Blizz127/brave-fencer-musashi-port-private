/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80131340 - byte-exact against retail at -O2 (tools/register_match.py). */
struct V8;
struct S80131E00;
struct V8 { char b[8]; };
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
void func_8012B23C(s32 a0);
void func_8012CBA4(s32 a0);
void func_8012CBF4(s32 a0);
void func_8012CC64(s32 a0, s32 a1);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
s32 func_8012DBD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131C78(s32 a0);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_801319E0(s32 a0);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern void func_8012B23C(s32 a0);
extern void func_8012CBF4(s32 a0);
extern void func_801319E0(int);
extern int func_80131D68(int, int);
extern void func_80131CA8(int, int);
extern void func_8012CBF4(s32);
extern s32 func_80131D68(s32 a0, s32 a1);
extern void func_80131E00(struct S80131E00*, s32);
extern s32 func_8012DBD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_8012CC64(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_80131E00();
extern s32 D_8018F018;
extern s32 D_8018F01C;

void func_80131340(s32 a0)
{
     


    struct V8 {
        u16 vx, vy, vz, pad;
    };
    extern struct V8 D_8017E6FC;
     




    extern int func_80131CF4(int, int);

    struct V8 sp10;
    struct V8 sp18;
    struct V8 sp20;
    struct V8 sp28;
    s32 temp;
    s32 var_a1;

    if (*(s16 *)(a0 + 0xA) >= 0x10) {
        func_801319E0(a0);
        return;
    }

    temp = func_80131CF4(*(s32 *)(a0 + 0xBC), 0x2E);
    if (temp != 0) {
        sp10.vz = 0;
        sp10.vx = 0;
        sp10.vy = temp;
    } else {
        sp10 = D_8017E6FC;
    }

    if (*(s32 *)(a0 + 0x10) != 0 || *(s32 *)(a0 + 0x18) != 0) {
        var_a1 = func_80131CF4(*(s32 *)(a0 + 0xBC), 0x19);
        if (var_a1 == 0) {
            var_a1 = 0x50;
        }
        func_8012DBD0(a0, var_a1,
                      *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) + 0x800, 0x1D);
    }

    switch (*(u8 *)(a0 + 0xC2)) {
    case 0:
    case 1:
        if (*(s32 *)(a0 + 0xC4) & 4) {
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x10) -= 0x100;
        }
        *(s32 *)(a0 + 0x1C) += 1;
        if (*(s32 *)(a0 + 0x1C) >= 0x3D) {
            func_80131E00(a0, 0xD);
            return;
        }
        if (*(u8 *)(a0 + 0xC2) == 0) {
            *(u8 *)(a0 + 0xC2) = 1;
            sp18.vx = *(u16 *)(a0 + 0x3A);
            sp18.vy = *(u16 *)(a0 + 0x3E);
            sp18.vz = *(u16 *)(a0 + 0x42);
            sp20 = sp18;
            sp20.vx += sp10.vx;
            sp20.vy += sp10.vy;
            sp20.vz += sp10.vz;
            sp28 = sp20;  
            func_8012CEB0((s32)&sp18, (s32)&sp20, 1);
            sp20.vx -= sp10.vx;
            sp20.vy -= sp10.vy;
            sp20.vz -= sp10.vz;
            *(u16 *)(a0 + 0x3A) = sp20.vx;
            *(u16 *)(a0 + 0x3E) = sp20.vy;
            *(u16 *)(a0 + 0x42) = sp20.vz;
            *(u16 *)(a0 + 0x6) = sp20.vx;
            *(u16 *)(a0 + 0xA) = sp20.vy;
            *(u16 *)(a0 + 0xE) = sp20.vz;
        }
        D_8018F018 = ((s32 (*)(s32, s32))func_8012CC64)(a0, (s32)&sp10);
        if (D_8018F018 & 0x8000) {
            *(s32 *)(a0 + 0x18) = 0;
            *(s32 *)(a0 + 0x10) = 0;
        }
        if (D_8018F018 & 0x4000) {
            func_8012B23C(a0);
            *(u8 *)(a0 + 0xC2) = 4;
        } else if (D_8018F018 & 0x2000) {
            if (func_80131D68(a0, D_8018F018) == 1) {
                return;
            }
            *(u8 *)(a0 + 0xC2) = 2;
            func_80143B6C(a0, 1);
            *(s32 *)(a0 + 0x14) = 0xFFF30000;
            *(s32 *)(a0 + 0x1C) = 0;
        } else if (D_8018F018 & 0x8000) {
            *(u8 *)(a0 + 0xC2) = 2;
            *(s32 *)(a0 + 0x1C) = 0;
            *(s32 *)(a0 + 0x18) = 0;
            *(s32 *)(a0 + 0x10) = 0;
        }
        break;

    case 2:
        if (*(s32 *)(a0 + 0xC4) & 4) {
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x10) -= 0x100;
        }
        *(s32 *)(a0 + 0x1C) += 1;
        if (*(s32 *)(a0 + 0x1C) >= 0x3D) {
            func_80131E00(a0, 0xD);
            return;
        }
        D_8018F01C = *(s32 *)(a0 + 0x14);
        D_8018F018 = ((s32 (*)(s32, s32))func_8012CC64)(a0, (s32)&sp10);
        if (D_8018F018 & 0x8000) {
            *(s32 *)(a0 + 0x18) = 0;
            *(s32 *)(a0 + 0x10) = 0;
        }
        if (D_8018F018 & 0x4000) {
            func_8012B23C(a0);
            *(u8 *)(a0 + 0xC2) = 4;
        } else if (D_8018F018 & 0x2000) {
            if (func_80131D68(a0, D_8018F018) == 1) {
                return;
            }
            func_80143B6C(a0, 1);
             
            *(s32 *)(a0 + 0x14) = (-D_8018F01C) / 3;
            *(s32 *)(a0 + 0x1C) = 0;
            *(u8 *)(a0 + 0xC2) = 3;
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0;
        } else if (D_8018F018 & 0x8000) {
            *(u8 *)(a0 + 0xC2) = 3;
            *(s32 *)(a0 + 0x1C) = 0;
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0;
            *(s32 *)(a0 + 0x18) = 0;
            *(s32 *)(a0 + 0x10) = 0;
        }
        break;

    case 3:
        *(s32 *)(a0 + 0x10) = *(s32 *)(a0 + 0x10) * 15 / 16;
        *(s32 *)(a0 + 0x18) = *(s32 *)(a0 + 0x18) * 15 / 16;
        if (*(u8 *)(a0 + 0xC3) & 1) {
            D_8018F018 = ((s32 (*)(s32))func_8012CBA4)(a0);
            if (D_8018F018 & 0x8000) {
                *(s32 *)(a0 + 0x18) = 0;
                *(s32 *)(a0 + 0x10) = 0;
            }
            if (func_80131D68(a0, D_8018F018) == 1) {
                return;
            }
            if (!(D_8018F018 & 0x6000)) {
                func_80131E00(a0, 0xD);
                return;
            }
        } else {
            D_8018F018 = ((s32 (*)(s32))func_8012CBF4)(a0);
            if (D_8018F018 & 0x8000) {
                *(s32 *)(a0 + 0x18) = 0;
                *(s32 *)(a0 + 0x10) = 0;
            }
            if (D_8018F018 & 0x4000) {
                func_8012B23C(a0);
                *(u8 *)(a0 + 0xC2) = 4;
                break;
            } else if (D_8018F018 & 0x2000) {
                if (func_80131D68(a0, D_8018F018) == 1) {
                    return;
                }
                *(u8 *)(a0 + 0xC3) |= 1;
            } else if (D_8018F018 & 0x8000) {
                *(s32 *)(a0 + 0x18) = 0;
                *(s32 *)(a0 + 0x10) = 0;
            }
        }
        if ((*(s32 *)(a0 + 0x1C) & 3) == 3) {
            func_80143B6C(a0, 1);
        }
        *(s32 *)(a0 + 0x1C) += 1;
        if (*(s32 *)(a0 + 0x1C) < 0x11) {
            break;
        }
        if (!(D_8018F018 & 0x6000)) {
            func_80131E00(a0, 0xD);
            return;
        }
         
        if (*(s16 *)(a0 + 0x76) <= 0) {
            func_80131E00(a0, 6);
        } else {
            func_80131C78(a0);
        }
        break;

    case 4:
        D_8018F018 = ((s32 (*)(s32))func_8012CBA4)(a0);
        if (D_8018F018 & 0x8000) {
            *(s32 *)(a0 + 0x18) = 0;
            *(s32 *)(a0 + 0x10) = 0;
        }
        if (D_8018F018 & 0x2000) {
            if (func_80131D68(a0, D_8018F018) == 1) {
                return;
            }
            if (*(s16 *)(a0 + 0x76) <= 0) {
                func_80131E00(a0, 6);
            } else {
                func_80131C78(a0);
            }
        } else {
            if ((*(s32 *)(a0 + 0x1C) & 3) == 3) {
                func_80143B6C(a0, 1);
            }
            *(s32 *)(a0 + 0x1C) += 1;
            if (*(s32 *)(a0 + 0x1C) >= 0x3D) {
                func_80131E00(a0, 0xD);
                return;
            }
        }
        break;
    }

    func_80131CA8(a0, 0x2F);
}
