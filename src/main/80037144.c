/* Exact retail word export for [80037144,80037334); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80037144 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

typedef struct { u8  v; } W8;

typedef struct {               
    s32 unk00;
    u8  unk04[0x14];
} Ent24;

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

typedef struct { u16 f0; } H2;

extern Slot16 D_80076244[];
extern W32   D_80076228;
extern s32   D_8007622C[];
extern W32   D_80076238;
extern Slot16A D_80076240[];
extern W8    D_80076242;
extern W8    D_80076243;
extern W32   D_80076294;
extern s32   D_8007629C;       
extern u8    D_800BA320[];
extern H2    D_80065438[];
extern s32   D_800652F0[];
extern Ent24 D_800A463C[];
extern s32   D_800A469C;
extern s16   D_800A46A0;
extern s16   D_800A46A2;
extern u8    D_800A46B0;

extern void  func_800415A8(s32);

void func_80037144(s32 idx) {
    s32 i;
    s32 k;
    s32 t;
    s32 v;
    s32 one;
    s32 ent;

    for (i = 0; i < 5; i++) {
        if (D_80076244[i].unk0D == 0) {
            break;
        }
    }
    if (i < 5) {
        one = 1;
        D_80076244[i].unk00 = (s32)D_800BA320;

        __asm__ __volatile__("" ::: "memory");
        D_80076244[i].unk0C = 0;
        D_80076244[i].unk0D = one;
        D_80076244[i].unk04 = idx | 0x2000;
        D_80076244[i].unk0E = 4;
        v = D_800652F0[D_80065438[idx].f0];
        D_800A469C = v;
        D_80076244[i].unk08 = v;
        k = 4;
        if (D_800A46B0 == 0) {
            if (D_800A46A0 == (D_80065438[idx].f0 | 0x4000)) {
                D_80076244[i].unk04 |= 0x1000;
                goto after;
            }
            t = D_800A46A2;
            D_800A46B0 = one;
        } else {
            t = D_800A46A2;
        }
        if (t >= 0) {
            func_800415A8(t);
            D_800A46A2 = -1;
        }
    after:
        if (i == 0) {
            D_8007622C[0] = (s32)D_800BA320;
            ent = D_800A463C[k].unk00;
            D_80076228.v = (s32)D_800BA320;
            D_80076240[0].unk00 = 0;
            D_80076243.v = 1;
            D_80076242.v = 0;
            D_80076294.v = 0;
            D_80076238.v = ent;
        }
    }
    D_8007629C = 0;
}
