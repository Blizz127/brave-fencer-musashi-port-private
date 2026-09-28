/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFFC - byte-exact against retail at -O2 (tools/register_match.py). */
struct S;
extern void func_801474EC(void *a0);
extern s32 func_800CB17C(struct S *a0);
extern void func_80146CA0(void *a0);

void func_800CAFFC(void *a0) {
        func_801474EC(a0);
        func_800CB17C((struct S *)a0);
        func_80146CA0(a0);
    }
