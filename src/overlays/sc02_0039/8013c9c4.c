/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013C9C4 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_80019064(void *);
extern s32 D_8019FA30;
extern M2C_UNK D_80062BC0;
extern s8 D_8019FA34;
extern s8 D_8019FA35;

void func_8013C9C4(void * arg0)
{
    D_8019FA30 = arg0;
    D_8019FA34 = 0;
    D_8019FA35 = 0;
    if (func_80019198() == 0) {
        func_80019064(&D_80062BC0);
    }
}
