/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016EAC0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    char _pad0;        
    unsigned char f1;  
    unsigned char f2;  
    char _pad3;        
    short f4;          
} Wave;
extern void func_8016EC0C(s32 a0, s32 a1);
extern u16 D_80181604[];

void func_8016EAC0(Wave *param_1)
{
    unsigned char bVar1;

    param_1->f4 = param_1->f4 + D_80181604[param_1->f2];
    ((void (*)(void *, int))func_8016EC0C)(param_1, 0x80);
    bVar1 = param_1->f2 + 1;
    param_1->f2 = bVar1;
    if (5 < bVar1) {
        param_1->f2 = 0x20;
        param_1->f1 = param_1->f1 + 1;
    }
}
