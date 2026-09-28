/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80132018 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8001C214(int, int);

void func_80132018(int param_1)
{

    extern int tbl_D_80187044[][5] __asm__("D_8017E204");
    extern int tbl_D_80187048[][5] __asm__("D_8017E208");
    int v0;

    v0 = ((int (*)(void))func_8012C1B8)();
    *(int *)(param_1 + 0x20) = v0;
    if (v0 == 0) {
        ((void (*)(int))func_8012CAE4)(param_1);
    } else {
        func_8001C214(v0, 0);
        *(short *)(param_1 + 0x5c) = 0x80;
        *(unsigned short *)(param_1 + 2) += 1;
        *(int *)(param_1 + 0x58) = (int)&tbl_D_80187048[*(unsigned short *)(param_1 + 0x70) & 0xfff];
        *(int *)(param_1 + 0xdc) = tbl_D_80187044[*(unsigned short *)(param_1 + 0x70) & 0xfff][0];
        *(short *)(param_1 + 0xfc) = (*(unsigned short *)(param_1 + 0x70) >> 12) << 9;
    }
}
