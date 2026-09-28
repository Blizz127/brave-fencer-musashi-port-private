/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF5E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80178970(s32 *a0);
extern void func_80178D18(u8 *a0);
extern s32 func_801858CC(s32);

void func_801EF5E4(u8 * a0)
{
    if (func_80178970(a0)) {
        func_80178D18((u8 *)a0);
        func_801858CC((s32)a0);
    }
}
