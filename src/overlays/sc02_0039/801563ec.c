/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801563EC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s32 a, b, c; } S801563EC;
extern S801563EC D_80181160[];

S801563EC *func_801563EC(u16 idx) {
    return &D_80181160[idx];
}
