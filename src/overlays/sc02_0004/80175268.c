/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80175268 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef void (*VoidFn)(void);
extern u8 D_80078EC0;

s32 func_80175268(s32 param_1)
{

    extern VoidFn D_80181384[];
    *(u32 *)(param_1 + 0x44) |= 2;
    (*(VoidFn *)((s32)D_80181384 + ((D_80078EC0 - 1) << 2)))();
}
