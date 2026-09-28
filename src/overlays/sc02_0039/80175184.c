/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80175184 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80182784[])(void*);
extern s32 func_80175268(s32);

void func_80175184(s32* arg0) {
    u16 v1 = *(u16*)((u8*)arg0 + 2);
    if (v1 < 2) {
        D_80182784[v1](arg0);
    } else {
        func_80175268((s32)arg0);
    }
}
