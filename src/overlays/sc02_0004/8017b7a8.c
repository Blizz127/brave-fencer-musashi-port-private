/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B7A8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_801961B4;
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

void func_8017B7A8(void)
{
    D_8012694C = 1;
    D_801961B4 = 0;
    D_8019622C = (s16) D_80114F30;
    D_8019622E = (s16) D_80114F34;
    D_80196230 = (s16) D_80114F38;
    D_80196224 = (s16) D_80114F24;
    D_80196226 = (s16) D_80114F28;
    D_80196228 = (s16) D_80114F2C;
}
