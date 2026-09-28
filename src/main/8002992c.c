/* Main-exec range [8002992C,80029A58) from the SLUS executable.
 * SHA256(span)=94cc5e6378b873fc26373efa1d3ac8d66ef81cfeafa8258425806eba69dba077.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8002992C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor typedefs this body depends on (copied from vendor/bfm-decomp). */
typedef struct {
    u16 unk00;
    u8  pad[14];
} T16;  /* 0x10 */
typedef struct {
    s32 words[38];
} Blk98_80029274;

typedef struct {
    u8 b[4];
} Blk4;

extern Blk98_80029274 D_80078E78;
extern u16 D_800A6588[];
extern u8 D_800BA2B8[];
extern u8 D_80078F28[];
extern u8 D_800AE648[];
extern u8 D_800BA1B8[];

void func_8002992C(s32 arg0) {
    u8* base;
    s32 i;

    base = D_80078F28 + arg0 * 0x2DC;
    D_80078E78 = *(Blk98_80029274*)(base + 0x24);

    for (i = 0; i < 0x40; i++) {
        D_800A6588[i] = *(u16*)(base + 0xBC + i * 2);
    }
    for (i = 0; i < 0x40; i++) {
        D_800AE648[i] = *(i + base + 0x13C);
    }
    for (i = 0; i < 0x100; i++) {
        D_800BA1B8[i] = *(i + base + 0x17C);
    }
    for (i = 0; i < 0x18; i++) {
        *(Blk4*)(D_800BA2B8 + i * 4) = *(Blk4*)(base + 0x27C + i * 4);
    }
}
