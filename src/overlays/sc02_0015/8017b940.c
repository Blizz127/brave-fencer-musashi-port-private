/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B940 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_8019028C;
extern u16 D_8019030C;
extern u16 D_8019030E;
extern u16 D_80190310;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_80190304;
extern s16 D_80190306;
extern s16 D_80190308;
extern s16 D_801902FC;
extern s16 D_801902FE;
extern s16 D_80190300;
extern u8  D_8012694C;
extern short D_80190314;
extern short D_80190316;
extern short D_80190318;

void func_8017B940(void)
{
    s32 buf[3];

    D_8012694C = 2;
    buf[0] = (*(s16 *)&D_80126B5E) - (*(s16 *)&D_8019030C);
    buf[1] = (*(s16 *)&D_80126B62) - (*(s16 *)&D_8019030E);
    buf[2] = (*(s16 *)&D_80126B66) - (*(s16 *)&D_80190310);
    (*(s16 *)&D_80190314) = buf[0];
    (*(s16 *)&D_80190316) = buf[1];
    (*(s16 *)&D_80190318) = buf[2];
    D_80190304 = D_80114F30 + buf[0];
    D_8019028C = 0;
    D_80190306 = D_80114F34 + buf[1];
    D_80190308 = D_80114F38 + buf[2];
    D_801902FC = D_80114F24 + buf[0];
    D_801902FE = D_80114F28 + buf[1];
    D_80190300 = D_80114F2C + buf[2];
}
