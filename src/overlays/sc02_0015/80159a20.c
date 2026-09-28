/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80159A20 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014900C(s32 *a0);
extern void func_8015126C(u16 *p);
extern void (*D_80180984[])(unsigned char *);
extern void func_80150B28(int param_1);
extern void func_80158638(unsigned char *);
extern void func_8015126C(unsigned short *);
extern void func_8014900C(int *a0);

void func_80159A20(unsigned char *param_1)
{
    typedef unsigned short u16;
    typedef unsigned int u32;
    typedef int s32;
    typedef unsigned char u8;

    ((s32 (*)(void))func_80150B28)();
    func_80158638(param_1);
    ((void (*)(u8 *))func_8015126C)(param_1);
    ((void (*)(u8 *))func_8014900C)(param_1);
    D_80180984[*(u16 *)param_1 & 0x7fff](param_1);
    *(u32 *)(param_1 + 0x44) |= 0x8000000;
    switch (*(u16 *)param_1) {
    case 2:
    case 3:
    case 0xb:
    case 0xc:
        goto mask;
    default:
        return;
    case 0x19:
        if (param_1[0xdd] != 1) {
            if (param_1[0xdd] == 4) {
                goto mask;
            }
            return;
        }
        if (*(u16 *)(param_1 + 2) == 3) {
            goto mask;
        }
        return;
    }
mask:
    *(u32 *)(param_1 + 0x44) &= 0xf7ffffff;
}
