/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB5C8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB5C8(s32 arg0, s32 arg1) {
    s32 count = 0;
    s16 t;
    if (*(u8 *)arg1 == 0) {
        (*(u16 *)arg0)++;
        (*(u16 *)((s8 *)arg0 + 2))++;
        count = *(s16 *)arg0 == 31;
        t = ++(*(u16 *)((s8 *)arg0 + 4));
        if (*(s16 *)((s8 *)arg0 + 2) == 31) count++;
        if (t == 31) count++;
    } else {
        (*(u16 *)arg0)--;
        (*(u16 *)((s8 *)arg0 + 2))--;
        t = --(*(u16 *)((s8 *)arg0 + 4));
        if (*(s16 *)arg0 == 0) count = 1;
        if (*(s16 *)((s8 *)arg0 + 2) == 0) count++;
        if (t == 0) count++;
    }
    if (count != 0) *(u8 *)arg1 ^= 1;
}
