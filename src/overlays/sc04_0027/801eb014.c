/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EB014 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EB014(void)
{
    typedef struct { s32 next; u8 pad[0xC]; } Node_801F28E0;
    extern s32 D_801F24A4;
    extern s32 D_801F2624;
    Node_801F28E0 *p;
    s32 i;

    p = (Node_801F28E0 *)&D_801F24A4;
    for (i = 0; i < D_801F2624 - 1; ) {
        p->next = (s32)(p + 1);
        i++;
        p = p + 1;
    }
}
