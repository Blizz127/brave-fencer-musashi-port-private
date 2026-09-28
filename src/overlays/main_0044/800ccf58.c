/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCF58 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCF58(arg0, arg1) void *arg0; s16 arg1; {
    *(s16 *)((u8 *)arg0 + 0x1C) = arg1;
    *(s16 *)((u8 *)arg0 + 0x1A) = arg1;
    *(s16 *)((u8 *)arg0 + 0x18) = arg1;
}
