/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014FDF4 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S8014FDF4;
struct S8014FDF4 {
    s16 pad0[3];    
    s16 f6;         
    s16 pad8;       
    s16 fA;         
    s16 padC;       
    s16 fE;         
    s16 pad[0x3C];  
    s16 f88;        
    s16 f8A;        
    s16 f8C;        
};
extern s32 func_80150170(void *a0);
extern s32 func_8014FE60();

void func_8014FDF4(struct S8014FDF4 *a0) {
    if (a0->f6 != a0->f88 || a0->fA != a0->f8A || a0->fE != a0->f8C) {
        func_80150170(a0);
    } else {
        func_8014FE60(a0);
    }
}
