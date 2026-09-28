/* Main-exec range [80037028,80037144) from the SLUS executable.
 * SHA256(span)=21c4a123dd5d7a5c0e254f72e0cb1644f79887e32f138c4575b66b87f919bf6f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80037028 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

typedef struct { u8  v; } W8;

typedef struct {               
    s32 unk00;
    u8  unk04[0x14];
} Ent24;

typedef struct {              
    u8  unk00;
    u8  pad[11];
} Elm12;

typedef struct {              
    u16 unk00;
    u16 unk02;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
} Slot16A;

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    u8  unk0C;
    u8  unk0D;
    u8  unk0E;
    u8  unk0F;
} Slot16;

typedef struct { s32 v; } W32;

extern Slot16A D_80076240[];
extern Slot16 D_80076244[];
extern Elm12   D_80064D49[];
extern Ent24   D_800A463C[];
extern u8  D_80076251;
extern s32 D_8007622C[];
extern W32 D_80076228;
extern W8  D_80076243;
extern W8  D_80076242;
extern W32 D_80076294;
extern W32 D_80076238;
extern s32 D_8007629C;

void func_80037028(s32 base, s32 val) {
    s32 slot;
    s32 i;
    s32 b;

    for (slot = 0, i = 0; slot < 5; slot++, i += 0x10) {
        if ((&D_80076251)[i] == 0) {
            break;
        }
    }

    if (slot < 5) {
        D_80076244[slot].unk0D = 1;
        D_80076240[slot].unk04 = val;
        D_80076244[slot].unk0C = 0;
        D_80076240[slot].unk08 = base;
        b = D_80064D49[base].unk00;
        D_80076244[slot].unk0E = b;
        D_80076240[slot].unk0C = D_800A463C[b].unk00;

        if (slot == 0) {
            s32 r;
            D_8007622C[0] = val;
            r = D_800A463C[b].unk00;
            D_80076228.v = val;
            D_80076240[0].unk00 = 0;
            D_80076243.v = 2;
            D_80076242.v = 0;
            D_80076294.v = 0;
            D_80076238.v = r;
        }
    }

    D_8007629C = 0;
}
