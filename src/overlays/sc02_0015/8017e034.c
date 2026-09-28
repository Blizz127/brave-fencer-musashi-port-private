/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E034 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80178B18(s32 param_1, s32 param_2);
extern s32 func_80178B18(s32, s32);
extern short D_80181DD4;

void func_8017E034(void * arg0) {
        *(short *)((char *)arg0 + 0x2) = 2;
        ((void (*)(s32, s32))func_80178B18)((int)arg0, (int)&D_80181DD4);
    }
