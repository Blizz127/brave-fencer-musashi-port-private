/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80131E7C - byte-exact against retail at -O2 (tools/register_match.py). */
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
s32 func_8012E470(s32 a0);
void func_8012E4C8(s32 a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_80131E00(struct S80131E00*, s32);
extern void func_80131E00();
void func_80131E00(struct S80131E00 *a0, s32 a1);
extern s32 func_8012E470(s32 a0);
extern void func_8012E4C8(s32 a0);

void func_80131E7C(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x40000) {
        if (func_8012E470(a0)) {
            func_8012E4C8(a0);
            func_80131E00((struct S80131E00 *)a0, 1);
        }
    }
    func_80131CA8(a0, 0x3A);
}
