/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80147CC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147928(int a0, int a1);
extern void func_8014799C(int a0, int a1);
extern void func_80147A10(int a0, int a1);
void func_80147928(int a0, int a1);
void func_8014799C(int a0, int a1);
void func_80147A10(int a0, int a1);
extern void func_80147DC0(s32 a0, s32 a1);

void func_80147CC8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_80147928(a0, a1);
    func_8014799C(a0, a2);
    func_80147A10(a0, a3);
    func_80147DC0(a0, a4);
}
