/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80130514 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_8012BEE8(s32 a0);
void func_8012CBF4(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_801319E0(s32 a0);
extern void func_8012CBF4(s32 a0);
extern void func_801319E0(int);
extern int func_80131D68(int, int);
extern int func_8012BEE8(int);
extern void func_80131CA8(int, int);

void func_80130514(int param_1)
{
    unsigned int uVar1;
    if ((*(unsigned int *)(param_1 + 0xb4) & 0x40) != 0) {
        uVar1 = ((int (*)(void))func_8012CBF4)();
        if (0xf < *(short *)(param_1 + 10)) {
            func_801319E0(param_1);
            return;
        }
        if (func_80131D68(param_1, uVar1) == 1) {
            return;
        }
        if (func_8012BEE8(param_1) != 0) {
            if ((uVar1 & 0x2000) != 0) {
                *(unsigned char *)(param_1 + 0xc1) = 0;
                *(unsigned short *)(param_1 + 0x5e) = 0;
                func_80131CA8(param_1, 0xe);
            }
        }
    }
     

    __asm__ __volatile__("");
    func_80131CA8(param_1, 0x13);
}
