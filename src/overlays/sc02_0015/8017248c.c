/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017248C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801724EC(s32 a0);

s32 func_8017248C(s32 arg0, s32 arg1)
{
    if (((s32 (*)(void*, void*))func_801724EC)(arg0, arg1) != 0) {
        *(u16*)((u8*)arg0 + 6) = *(u16*)((u8*)arg1 + 0);
        *(u16*)((u8*)arg0 + 0xA) = *(u16*)((u8*)arg1 + 2);
        *(u16*)((u8*)arg0 + 0xE) = *(u16*)((u8*)arg1 + 4);
        return 1;
    }
    return 0;
}
