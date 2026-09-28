/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B940 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_801961B4;
extern u16 D_80196234;
extern u16 D_80196236;
extern u16 D_80196238;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_8019622C;
extern s16 D_8019622E;
extern s16 D_80196230;
extern s16 D_80196224;
extern s16 D_80196226;
extern s16 D_80196228;
extern u8  D_8012694C;
extern short D_8019623C;
extern short D_8019623E;
extern short D_80196240;

void func_8017B940(void)
{
    s32 buf[3];

    D_8012694C = 2;
    buf[0] = (*(s16 *)&D_80126B5E) - (*(s16 *)&D_80196234);
    buf[1] = (*(s16 *)&D_80126B62) - (*(s16 *)&D_80196236);
    buf[2] = (*(s16 *)&D_80126B66) - (*(s16 *)&D_80196238);
    (*(s16 *)&D_8019623C) = buf[0];
    (*(s16 *)&D_8019623E) = buf[1];
    (*(s16 *)&D_80196240) = buf[2];
    D_8019622C = D_80114F30 + buf[0];
    D_801961B4 = 0;
    D_8019622E = D_80114F34 + buf[1];
    D_80196230 = D_80114F38 + buf[2];
    D_80196224 = D_80114F24 + buf[0];
    D_80196226 = D_80114F28 + buf[1];
    D_80196228 = D_80114F2C + buf[2];
}
