/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B7A8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_801A0BE4;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801A0C5C;
extern s16 D_801A0C5E;
extern s16 D_801A0C60;
extern s16 D_801A0C54;
extern s16 D_801A0C56;
extern s16 D_801A0C58;

void func_8017B7A8(void)
{
    D_8012694C = 1;
    D_801A0BE4 = 0;
    D_801A0C5C = (s16) D_80114F30;
    D_801A0C5E = (s16) D_80114F34;
    D_801A0C60 = (s16) D_80114F38;
    D_801A0C54 = (s16) D_80114F24;
    D_801A0C56 = (s16) D_80114F28;
    D_801A0C58 = (s16) D_80114F2C;
}
