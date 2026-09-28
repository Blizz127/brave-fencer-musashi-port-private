/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80130278 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131170();
extern void func_80131CA8();
extern void func_80131170(s32 a0, s32 a1, s32 a2);
extern void func_80131CA8(s32 a0, s32 a1);

void func_80130278(s32 arg0) {
    s32 flag;
    flag = 0;
    *(u8 *)(arg0 + 0xC1) = 0xB;
    if (*(s32 *)(arg0 + 0xC4) & 1) {
        func_80131E00((struct S80131E00 *)arg0, 0xE);
        return;
    }
    if (*(s32 *)(arg0 + 0xB4) & 0x800) {
        func_80131170(arg0, 0, 0);
        flag = 1;
    }
    if (((s32 (*)(int, int))func_80131CA8)(arg0, 0x2C) != 0) {
        flag = 1;
    }
    if (flag == 0) {
        func_80131E00((struct S80131E00 *)arg0, 6);
    }
}
