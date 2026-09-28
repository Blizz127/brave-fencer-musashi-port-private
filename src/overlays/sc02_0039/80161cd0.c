/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161CD0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 arg0);
extern s32 func_800CF8B4();
extern void func_80147324(s32 a0);
extern s32 func_800CF8B4(void);
extern s32  func_800CF8B4();
extern void func_80147324();
extern int func_800CF8B4();
extern void func_80147324(int arg0);
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");

void aF80161CD0(int param_1, unsigned int param_2)
{

    extern unsigned short D_80181BE4;
    if (param_2 < 8) {
        if (func_800CF8B4() != 0) {
            func_80147324((&D_80181BE4)[param_2]);
        }
    }
}
