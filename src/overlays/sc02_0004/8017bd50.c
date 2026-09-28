/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017BD50 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80196350;
void func_8017B0E4(int param_1, int param_2);
extern s16 D_801961B4;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern short D_8019623C;
extern short D_8019623E;
extern short D_80196240;
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);
extern void (*D_801961F8)(void);

void func_8017BD50(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801961B4 = D_801961B4 + 1;
    if (D_801961B4 >= 0x19) {
        if (D_801961F8 != 0) {
            (*D_801961F8)();
        } else {
            D_80114F30 = D_80114F30 + D_8019623C;
            D_80114F34 = D_80114F34 + D_8019623E;
            D_80114F38 = D_80114F38 + D_80196240;
            D_80114F24 = D_80114F24 + D_8019623C;
            D_80114F28 = D_80114F28 + D_8019623E;
            D_80114F2C = D_80114F2C + D_80196240;
            func_8012A4BC();
        }
        D_80196350 = 0;
    }
}
