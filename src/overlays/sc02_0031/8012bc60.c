/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012BC60 - byte-exact against retail at -O2 (tools/register_match.py). */
#define Square0 func_80049324
struct Vec;
struct Vec {
    s16 unk0;
    s16 unk2;   
    s16 unk4;
    s16 unk6;   
    s16 unk8;
    s16 unkA;   
};
typedef struct { short vx, vy, vz, pad; } Vec;
extern void Square0(s32 *a0, s32 *a1);

s32 func_8012BC60(struct Vec *a0, struct Vec *a1) {
    s32 d[3];
    d[0] = a0->unk2 - a1->unk2;
    d[1] = a0->unk6 - a1->unk6;
    d[2] = a0->unkA - a1->unkA;
    Square0(d, d);
    return d[0] + d[1] + d[2];
}
