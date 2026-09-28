/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B7A8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_8019028C;
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

void func_8017B7A8(void)
{
    D_8012694C = 1;
    D_8019028C = 0;
    D_80190304 = (s16) D_80114F30;
    D_80190306 = (s16) D_80114F34;
    D_80190308 = (s16) D_80114F38;
    D_801902FC = (s16) D_80114F24;
    D_801902FE = (s16) D_80114F28;
    D_80190300 = (s16) D_80114F2C;
}
