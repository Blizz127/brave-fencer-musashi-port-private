/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80148C9C - byte-exact against retail at -O2 (tools/register_match.py). */
struct Obj;
struct Obj {
    short unk0;
    unsigned short idx;
};
typedef struct { char pad[0x12]; s16 field_0x12; } Obj;

s32 func_80148C9C(s32 a0, s32 a1) {
    Obj *p = *(Obj **)((s32)a0 + 0x20);
    p->field_0x12 = (a1 + 0x400) & 0xFFF;
    return 1;
}
