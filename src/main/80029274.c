/* Exact retail word export for [80029274,8002931C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80029274 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor typedefs this body depends on (copied from vendor/bfm-decomp). */
typedef struct {
    u16 unk00;
    u8  pad[14];
} T16;  /* 0x10 */
typedef struct {
    s32 words[38];
} Blk98_80029274;

extern Blk98_80029274 D_80072C84;
extern Blk98_80029274 D_80078E78;

void func_80029274(void) {
    Blk98_80029274 buffer;

    buffer = D_80072C84;
    D_80078E78 = buffer;
}
