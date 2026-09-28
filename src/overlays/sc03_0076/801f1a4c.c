/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F1A4C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801F34DC[];
void func_800167B8(int);
void func_80175414(s32 _arg0);

int func_801F1A4C(u8 *arg) {
    extern u8 *D_80126B10;
    D_80126B10 = D_801F34DC;
    func_800167B8(0);
    ((void (*)(void))func_80175414)();
    arg[0x15]++;
    return 0;
}
