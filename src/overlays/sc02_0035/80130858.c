/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80130858 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_8012AD80(s32 a0);
s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32);
extern void func_801319E0(s32 a0);
extern void func_801319E0(int);
extern int func_8012BEE8(int);
extern void func_8012AD80(s32 a0);

void func_80130858(s32 a0) {
    func_8012AD80(a0);
    if (func_8012BEE8(a0)) {
        func_801319E0(a0);
    }
}
