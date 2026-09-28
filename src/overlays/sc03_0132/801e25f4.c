/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E25F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 *D_80126B10;
extern u8 D_801E304C[];
extern void func_80175414(s32 _arg0);
void func_800167B8(int);

int func_801E25F4(u8 *arg) {
    extern u8 *D_80126B10;
    D_80126B10 = D_801E304C;
    func_800167B8(0);
    ((void (*)(void))func_80175414)();
    arg[0x15]++;
    return 0;
}
