/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80152BF0 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80146CA0(void *a0);
void func_80149020(s32 *a0);
extern void func_80019064(void *a0);
extern int func_80151204(int arg, int a1);
int func_80151204(int a0, int a1);
extern void func_80146CA0(void *a0);
extern void func_80149020(s32 *a0);
extern s32 D_80062C14;

void func_80152BF0(s32 a0)
{
    func_80019064(&D_80062C14);
    func_80151204((int)a0, *(s16 *)((s32)a0 + 0xF2));
    func_80149020((s32 *)a0);
    func_80146CA0(a0);
}
