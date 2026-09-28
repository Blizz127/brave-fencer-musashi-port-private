/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016A1CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EBF;
extern void func_80147324(s32 arg0);
extern void func_80147364();
extern void func_80146C3C();

void func_8016A1CC(int param_1)
{
    register int iVar1 __asm__("$2");
    if (D_80078EBF != 0) {
        iVar1 = D_80078EBF - 0x18;
        *(int *)(param_1 + 0x30) = iVar1;
        if (iVar1 >= 0) {
            iVar1 = *(int *)(param_1 + 0x1c) + 1;
            *(int *)(param_1 + 0x1c) = iVar1;
            if (iVar1 == 4) {
                func_80147324(0x44c);
            }
            if (D_80078EBF >= 0x80) {
                if (*(short *)(param_1 + 0x2a) == 0) {
                    *(short *)(param_1 + 0x2a) = 1;
                    *(int *)(param_1 + 0x1c) = 0x100;
                }
                if ((*(unsigned int *)(param_1 + 0x1c) & 0x1f) == 0) {
                    func_80147324(0x44d);
                }
            }
        }
    } else {
        ((void (*)(int, int))func_80147364)(4, 0x44c);
        ((void (*)(int))func_80146C3C)(param_1);
    }
}
