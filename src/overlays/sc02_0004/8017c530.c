/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017C530 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ReadGeomOffset func_800491CC
#define RotTransPers func_8004955C
extern void ReadGeomOffset(s32 *a0, s32 *a1);
extern s32 RotTransPers(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void func_8004921C(s32 a0, s32 a1);

void func_8017C530(s32 a0, s32 a1) {
    s32 ofx;
    s32 ofy;
    s32 sxy;
    s32 p;
    ReadGeomOffset(&ofx, &ofy);
    func_8004921C(0, 0);
    RotTransPers(a0, a1, &sxy, &p);
    func_8004921C(ofx, ofy);
}
