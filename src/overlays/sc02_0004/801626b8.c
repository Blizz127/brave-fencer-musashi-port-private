/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801626B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800291DC(s32);
extern int func_800291DC(int);
extern int func_800D0E30(void *a0);

int func_801626B8(void) {
    short local;
    int lo;
    local = func_800291DC(0x12) & 0x7FFF;
    local = func_800D0E30(&local);
    lo = *(unsigned char *)&local;
    return (short)(*((unsigned char *)&local + 1) * 100 + lo);
}
