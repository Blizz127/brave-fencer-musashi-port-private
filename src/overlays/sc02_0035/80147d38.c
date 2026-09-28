/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80147D38 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147948(s32 a0, s32 a1, s32 a2);
extern void func_801479BC(s32 a0, s32 a1, s32 a2);
extern void func_80147A30(s32 a0, s32 a1, s32 a2);
extern void func_80147948(int a0, int a1, int a2);
void func_80147948(s32 a0, s32 a1, s32 a2);
extern void func_801479BC(int a0, int a1, int a2);
void func_801479BC(s32 a0, s32 a1, s32 a2);
extern void func_80147A30(int a0, int a1, int a2);
void func_80147A30(s32 a0, s32 a1, s32 a2);
extern void func_80147DC0(s32 a0, s32 a1);

void func_80147D38(s32 a0, s32 a1, s32 a2, s32 a3, void * a4)
{
    func_80147948(a0, a1, 0x7FFFFFFF);
    func_801479BC(a0, a2, 0x7FFFFFFF);
    func_80147A30(a0, a3, 0x7FFFFFFF);
    func_80147DC0(a0, a4);
}
