/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB400 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);
void func_800CAF84();
extern void func_800CAF84();

void func_800CB400(void *a0)
{
    extern void func_800CAF84(void);
    s16 var;

    var = *(u16 *)((u8 *)a0 + 0x28) - 0x100;
    *(u16 *)((u8 *)a0 + 0x28) = var;
    if (var > 0) {
        *(s32 *)((u8 *)a0 + 0x50) -= 2;
        func_800CAF84();
    } else {
        func_80146C3C();
    }
}
