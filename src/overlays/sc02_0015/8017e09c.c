/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E09C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B9C;
extern u16 D_80126B5E;
void func_8017E034(void * arg0);
void func_8017E034(void *arg0);

void func_8017E09C(void) {
    if ((D_80126B9C & 0x08000000) && (*(s16 *)&D_80126B5E < 0x90)) {
        ((void (*)(void))func_8017E034)();
    }
}
