/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015AC48 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_80161CD0(s32 a0, s32 a1);
extern M2C_UNK D_8018030C;

void func_8015AC48(s32 arg0)
{
    func_80154150(arg0, 9);
    func_80146DB8((s32 *)arg0, &D_8018030C);
    func_80161CD0(arg0, (*(  u16 * )((s8 *)( arg0 ) + (  0x16E ))) );
}
