/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E22C - byte-exact against retail at -O2 (tools/register_match.py). */
#define Square12 func_800492FC
struct VecA;
struct VecB;
struct VecA {
    s16 unk0;
    s16 unk2;   
    s16 unk4;
    s16 unk6;   
    s16 unk8;
    s16 unkA;   
};
struct VecB {
    s16 unk0;   
    s16 unk2;   
    s16 unk4;   
};
extern void Square12(s32 *a0, s32 *a1);

s32 func_8013E22C(struct VecA *a0, struct VecB *a1) {
    s32 d[3];
    s32 sq[3];
    d[0] = a0->unk2 - a1->unk0;
    d[1] = a0->unk6 - a1->unk2;
    d[2] = a0->unkA - a1->unk4;
    Square12(d, sq);
    return sq[0] + sq[1] + sq[2];
}
