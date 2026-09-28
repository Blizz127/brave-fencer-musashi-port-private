/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A828 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012AAAC();

void func_8012A828(s32 a0, void * a1)
{
    *(s32 *)((u8 *)a0 + 0x90) = a1;
    *(s32 *)((u8 *)a0 + 0x94) = 0;
    *(s32 *)((u8 *)a0 + 0x9C) = 0;
    *(s16 *)((u8 *)a0 + 0x9A) = 0;
    *(u16 *)((u8 *)a0 + 0x72) = *(u16 *)((u8 *)a0 + 0x72) & 0xF9FF;
    func_8012AAAC();
}
