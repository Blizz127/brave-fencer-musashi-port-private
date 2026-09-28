/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB6D4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB6D4(void *a0)
{
    extern void func_800CB76C(void *arg0);

    if (*(u16 *)*(s32 *)((u8 *)a0 + 0x34) == 0) {
        *(u16 *)((u8 *)a0 + 2) = *(u16 *)((u8 *)a0 + 2) + 1;
    } else {
        func_800CB76C(a0);
    }
}
