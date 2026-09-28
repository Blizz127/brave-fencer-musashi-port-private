/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB8A8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB8A8(void *arg0, s16 arg1) {
    u16 *ptr = *(u16 **)((s32)arg0 + 0x20);
    ptr[13] = ptr[13] - arg1;
    ptr[12] = ptr[13];
}
