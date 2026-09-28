/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B940 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_801A0BE4;
extern u16 D_801A0C64;
extern u16 D_801A0C66;
extern u16 D_801A0C68;
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
extern u8  D_8012694C;
extern short D_801A0C6C;
extern short D_801A0C6E;
extern short D_801A0C70;

void func_8017B940(void)
{
    s32 buf[3];

    D_8012694C = 2;
    buf[0] = (*(s16 *)&D_80126B5E) - (*(s16 *)&D_801A0C64);
    buf[1] = (*(s16 *)&D_80126B62) - (*(s16 *)&D_801A0C66);
    buf[2] = (*(s16 *)&D_80126B66) - (*(s16 *)&D_801A0C68);
    (*(s16 *)&D_801A0C6C) = buf[0];
    (*(s16 *)&D_801A0C6E) = buf[1];
    (*(s16 *)&D_801A0C70) = buf[2];
    D_801A0C5C = D_80114F30 + buf[0];
    D_801A0BE4 = 0;
    D_801A0C5E = D_80114F34 + buf[1];
    D_801A0C60 = D_80114F38 + buf[2];
    D_801A0C54 = D_80114F24 + buf[0];
    D_801A0C56 = D_80114F28 + buf[1];
    D_801A0C58 = D_80114F2C + buf[2];
}
