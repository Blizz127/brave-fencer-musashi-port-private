/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013C9C4 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_80019064(void *);
extern s32 D_8018F0D8;
extern M2C_UNK D_80062BC0;
extern s8 D_8018F0DC;
extern s8 D_8018F0DD;

void func_8013C9C4(void * arg0)
{
    D_8018F0D8 = arg0;
    D_8018F0DC = 0;
    D_8018F0DD = 0;
    if (func_80019198() == 0) {
        func_80019064(&D_80062BC0);
    }
}
