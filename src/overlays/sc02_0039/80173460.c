/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80173460 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S80126B38;
struct S80126B38 { s32 a; s32 b; } __attribute__((packed));
extern void func_801734BC(s32 a0, s32 a1);
extern struct S80126B38 D_80126B38;
extern s16 D_80126B3E;

void func_80173460(s32 a0, s32 a1) {
    func_801734BC(a0, a1);
    D_80126B38 = *(struct S80126B38 *)a1;
    D_80126B3E = 1;
}
