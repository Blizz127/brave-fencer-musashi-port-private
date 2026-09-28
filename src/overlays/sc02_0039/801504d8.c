/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801504D8 - byte-exact against retail at -O2 (tools/register_match.py). */
struct V3;
struct V3 { s16 x; s16 y; s16 z; };
typedef struct { s16 x, y, z; } V3;
extern s32 func_80150528(void *a0, void *a1, void *a2);

void func_801504D8(u16 *a0) {
    struct V3 a;
    struct V3 b;
    s32 t6 = a0[3];    
    s32 ta;
    s32 te;
    b.x = t6;
    a.x = t6;
    ta = a0[5];        
    a.y = ta - 3;
    te = a0[7];        
    b.y = ta + 1;
    b.z = te;
    a.z = te;
    func_80150528(a0, &a, &b);
}
