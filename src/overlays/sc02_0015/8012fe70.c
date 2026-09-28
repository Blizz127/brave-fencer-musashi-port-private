/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012FE70 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_8012FE70(s32 a0) {
    s32 v1 = *(s32 *)(a0 + 0xC4);
    *(u8 *)(a0 + 0xC1) = 9;
    if (v1 & 2) {
        *(u8 *)(a0 + 0xC1) = 1;
        func_80131CA8(a0, 3);
    } else if (v1 & 1) {
        func_80131E00((struct S80131E00 *)a0, 1);
    } else {
        if (*(s32 *)(a0 + 0xB4) & 0x200) {
            func_80131170(a0, 0, 0);
        }
        func_80131CA8(a0, 0x1E);
    }
}
