/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149B54 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 func_8014BEF8(void);

s32 func_80149B54(s32 * arg0)
{
    s32 var_v0;
    u32 temp;
    if ((*(u32*)((u8*)arg0 + 0x44) & 0x400) != 0) { var_v0 = 0; goto end; }
    if (((s32(*)(s32*))func_8014BEF8)(arg0) == 0) { var_v0 = 0; goto end; }
    temp = *(u16*)((u8*)arg0 + 0xAC) & 0x10;
    var_v0 = temp != 0;
end:
    return var_v0;
}
