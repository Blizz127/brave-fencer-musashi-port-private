/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801627E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8011F750;

void func_801627E8(void)
{

    extern s32 D_8011F750;                
    extern void (*D_80180DE8[])(void);    
    register u8 *p __asm__("$4") = (u8 *)&D_8011F750;
    s32 idx;

    __asm__ __volatile__("" : "=r"(p) : "0"(p));    
    idx = *p;
    if (idx != 0) {
        idx = idx - 1;
        D_80180DE8[idx]();
    }
}
