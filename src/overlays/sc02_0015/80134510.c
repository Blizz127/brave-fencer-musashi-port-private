/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80134510 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u16 f0;    
    u16 f2;    
    u16 f4;    
    s16 f6;    
} Foo_80134510_80134510;
extern s32 D_8018F060;

s32 func_80134510(s32 param) {
    extern s32 func_801345F8(s32);
    extern Foo_80134510_80134510 * D_8017E7D4;
    extern Foo_80134510_80134510 * D_8017E7D8;
    extern Foo_80134510_80134510 * D_8017E7DC;
    extern u16 D_8018F070;


    s32 ret = 0;
    Foo_80134510_80134510 *b0 = D_8017E7D8;
    Foo_80134510_80134510 *ac = D_8017E7D4;
    u16 t0 = ((Foo_80134510_80134510 *)param)->f0;
    u16 t2, t4;

    ((Foo_80134510_80134510 *)param)->f6 = 0;
    ac->f0 = t0;
    b0->f0 = t0;
    t2 = ((Foo_80134510_80134510 *)param)->f2;
    ac->f2 = t2 - 4;
    b0->f2 = t2 + 0x2FC;
    t4 = ((Foo_80134510_80134510 *)param)->f4;
    ac->f4 = t4;
    b0->f4 = t4;

    if (func_801345F8((*(s32*)&D_8018F060)) != 0) {
        s16 x;
        ((Foo_80134510_80134510 *)param)->f2 = D_8017E7DC->f2 - 2;
        x = D_8017E7D4->f6;
        if (x >= -3019) {
            if (x < -1400) {
                ret = 0x4000;
            } else {
                ret = 0x8000;
            }
        } else {
            ret = 0x2000;
        }
        D_8017E7D4->f6 = D_8018F070;
    }
    return ret;
}
