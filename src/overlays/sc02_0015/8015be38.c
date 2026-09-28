/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015BE38 - byte-exact against retail at -O2 (tools/register_match.py). */
struct Obj;
struct Obj {
    short unk0;
    unsigned short idx;
};
typedef struct { char pad[0x12]; s16 field_0x12; } Obj;

void func_8015BE38(struct Obj *a0) {

    extern void (*D_80180A54[])(void);
    D_80180A54[*(u16 *)((s32)a0 + 0x2)]();
}
