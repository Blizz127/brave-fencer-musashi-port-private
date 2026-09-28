/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017044C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801151D4;
extern void func_80171928(void *a0);
extern void func_80171928(void *);
extern s16 func_80171AB0(s32 a0, void *a1);

void func_8017044C(u8 * a0)
{
    s16 buf[3];
    s32 *p;
    p = (s32 *)D_801151D4;
    buf[0] = (s16)p[0xF];    
    buf[1] = (s16)p[0x10];   
    buf[2] = (s16)p[0x11];   
    if (func_80171AB0(a0, buf) == 0) {
        func_80171928((void *)a0);
    }
}
