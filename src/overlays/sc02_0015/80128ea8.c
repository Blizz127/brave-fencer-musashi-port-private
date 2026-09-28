/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128EA8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80128EA8(s32 a0, s32 a1, s32 a2) {
    *(s32 *)(a1 + 0x0) = a2;                        
    *(s16 *)(a1 + 0x4) = 0;                          
    *(s16 *)(a1 + 0x6) = (*(s32 *)(a2 + 0x4)) & 0x3F;  
    *(s16 *)(a0 + 0x28) = *(u16 *)(a2 + 0x0);       
    *(s16 *)(a0 + 0x2A) = *(u16 *)(a2 + 0x2);       
}
