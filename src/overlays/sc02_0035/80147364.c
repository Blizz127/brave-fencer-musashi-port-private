/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80147364 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern s32 D_80126B58;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80015978(s32 a0, s32 *a1);
extern s16 currentLocationId;
extern void func_80015978(s32, s32*);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
void aF80147364(u16 param_1, u16 param_2) __asm__("func_80147364");

void aF80147364(u16 param_1, u16 param_2) {
    s32 sp10[2];
    s32 *p = &D_80126B58;
    if (currentLocationId == 0x308d) {
        ((void (*)(void *, void *))func_80015978)(p + 1, sp10);
        ((void (*)(void *, s32, s32))aF8012E5CC)(sp10, param_1, param_2);
    } else {
        func_8002D4C8(param_1, param_2);
    }
}
