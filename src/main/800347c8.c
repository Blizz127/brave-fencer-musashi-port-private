/* Main-exec range [800347C8,80034844) from the SLUS executable.
 * SHA256(span)=5cfd35207a748f71ba6935eac5aae5f7ccae6c9eb41edd1ec29bd3906e8bb007.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_800347C8 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
    u16 state;      
    u16 unk02;
    u16 id;         
    u16 group;      
    u16 unk08;
    s8  unk0A;
    u8  unk0B;
    u8  pad0C[0xA];
    u8  active;     
    u8  pad17[0x3D];
} Sl;
extern u16 D_800A46E8[];

void func_800347C8(s32 arg0) {
    Sl *e;
    s32 i;

    e = (Sl *)D_800A46E8;
    for (i = 0; i < 8; i++, e++) {
        if (e->state == 5 && e->id == (s16)arg0 &&
            ((arg0 >> 16) == 0 || (arg0 >> 16) == e->group)) {
            e->active = 1;
        }
    }
}
