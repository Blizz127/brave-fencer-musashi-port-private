/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F68C - byte-exact against retail at -O2 (tools/register_match.py). */
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
s32 func_8012BEE8(s32 a0);
void func_8012CBCC(s32 a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_8012CBCC(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_80131C78(s32 a0);

void func_8012F68C(s32 arg0) {
    s32 flag;
    u32 cond;
    flag = 0;
    if (!(*(u32 *)(arg0 + 0xC4) & 2) && (*(u32 *)(arg0 + 0xB4) & 1)) {
        if ((u8)((s32 (*)(s32))func_8012CBCC)(arg0) == 2) {
            func_80131E00((struct S80131E00 *)arg0, 0x12);
            return;
        }
        if (*(u8 *)(arg0 + 0xC2) != 0) {
            cond = func_8012BEE8(arg0);
        } else {
            cond = *(u16 *)(arg0 + 0x72) & 0x4000;
        }
        if (cond != 0) {
            flag = 1;
        }
        if (flag != 0) {
            func_80131C78(arg0);
        }
    }
    func_80131CA8(arg0, 5);
}
