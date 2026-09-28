/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F2930 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern void func_80029124(s32, s32);
extern void func_80029124(s32 a0, s32 a1);
extern void func_80029514(s32 arg0);

void func_801F2930(void) {
    func_80029124(0xFD, 0x1);
    if (((s32 (*)(void))func_80029504)() == 0x136) {
        ((void (*)(s32))func_80029514)(0x140);
    }
}
