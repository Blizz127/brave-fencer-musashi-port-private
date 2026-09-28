/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801301E8 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_8012BEE8(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_801319E0(s32 a0);
extern void func_80130D48(s32 a0);

void func_801301E8(u8 *a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x2000) {
        if (*(u8 *)(a0 + 0xC3) != 0) {
            if (*(u16 *)(a0 + 0x72) & 0x4000) {
                func_80130D48((s32)a0);
                func_801319E0((s32)a0);
            }
        } else if (func_8012BEE8((s32)a0) != 0) {
            func_80130D48((s32)a0);
            func_801319E0((s32)a0);
        }
    }
    func_80131CA8((int)a0, 0x26);
}
