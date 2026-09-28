/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016A890 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_80146C3C(void);
extern s32 func_8016A8FC(s32 a0);

void func_8016A890(s32 arg0)
{
    s16 *p = *(s16 **)((u8 *)arg0 + 0x34);
    if (*(s32 *)((u8 *)arg0 + 0x1C) < 4 && *(u16 *)p == 0x14) {
        ((void (*)(void))func_8016A8FC)();
        *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)((u8 *)arg0 + 0x1C) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)(arg0);
    }
}
