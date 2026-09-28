/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F14C - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransSV func_8004945C
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void RotTransSV(s32 a0, s32 a1, void *a2);

void func_8012F14C(s32 a0, s32 a1, s32 a2)
{
    s32 buf[2];
    func_8004914C((void *)a0);
    func_800491AC((void *)a0);
    RotTransSV(a1, a2, buf);
}
