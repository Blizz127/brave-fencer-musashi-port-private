/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161034 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80149020(s32 *a0);
extern void func_80159B70(void *a0);
extern void (*D_80181798[])(void *);
extern void func_80159B70(void*);
extern void (*D_80181798[])(void*);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *);
extern void func_80147078(s32 *, s16);

void func_80161034(void *a0)
{
    func_80149020(a0);
    D_80181798[*(u16 *)a0](a0);
    func_80147078(a0, 0);
    func_80159B70(a0);
}
