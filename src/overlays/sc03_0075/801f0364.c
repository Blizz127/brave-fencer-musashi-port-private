/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F0364 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 *D_80126B10;
extern void func_80029124(s32, s32);
extern void func_80174438(s32 a0);
extern void func_80029514(s32 a0);
extern void func_80029124(s32 arg0, s32 arg1);

void func_801F0364(void) {
    func_80029514(0x12C);
    func_80174438((s32)D_80126B10);
    func_80029124(0x10F, 1);
}
