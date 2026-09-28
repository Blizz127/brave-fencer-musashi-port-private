/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB1A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern s32 func_80161208();
extern s32 func_80165A20(s32 a0);
extern u16 func_80148800(s32 *a0);
extern void func_8012A62C(s32 a0);
extern void func_80159B3C(void *a0);
extern s32 D_80078EC8;

void func_800CB1A0(s32 a0) {
    if (func_80161208(a0) != 0) {
        func_80165A20(a0);
        return;
    }
    if ((func_80148800(a0) & 0x20) != 0 || D_80078EC8 == 0) {
        func_8012A62C(0x10);
        func_80165A20(a0);
        func_801599A4(a0);
        func_80159B3C(a0);
    } else {
        *(u16 *)(a0 + 0x15A) = 1;
    }
}
