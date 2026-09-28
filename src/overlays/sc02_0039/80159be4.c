/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80159BE4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);
extern s32 func_80172590(u8 *a0);
extern unsigned char D_801816FC;

void func_80159BE4(s32 arg0)
{
    int v;

    ((void (*)(int, void *))func_80146DB8)(arg0, &D_801816FC);
    if ((*(unsigned int *)(arg0 + 0x44) & 0x200) != 0) {
        func_80154150(arg0, 5);
        func_80154A74(arg0, 0x1C);
    } else {
        func_80154150(arg0, 4);
        func_80154A74(arg0, 0x11);
    }
    *(int *)(arg0 + 0x234) = 0;
    *(int *)(arg0 + 0x238) = 0;
    func_801553C0(arg0);
    ((void (*)(int))func_801553A8)(arg0);
    ((void (*)(int))func_80172590)(arg0);
    ((void (*)(int))func_80146CA0)(arg0);
}
