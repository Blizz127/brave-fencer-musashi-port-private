/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801319E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012C218(void *a0);
void func_8012C218(void *a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_8002A04C(s32 a0);

void func_801319E0(s32 arg0) {
     

    if (((s32 (*)(int, int))func_80131CA8)(arg0, 0x11) == 0) {
        if (*(s32 *)(arg0 + 0x78) != 0) {
            func_8002A04C(arg0);
        }
        func_8012C218((void *)arg0);
    }
}
