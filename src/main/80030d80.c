/* Exact retail word export for [80030D80,80030F80); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80030D80 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct Ent30D80 {
     s32 unk00;
     u8 pad04[6];
     u16 unk0A;
     u8 pad0C[0x34];
     void (*unk40)(s32, s32);
     s32 unk44;
     u8 pad48[6];
     u8 unk4E;
     u8 pad4F;
     u8 unk50;
     u8 unk51;
} Ent30D80;
extern void func_80030D80(Ent30D80 *arg0, s16 arg1);
typedef struct Blk48_30D80 {
     s32 unk00;
     u8 pad04[0x3D];
     u8 unk41;
     u8 pad42[6];
} Blk48_30D80;
extern s8 D_800A4F17;
extern s32 D_800C7D20;
extern s32 D_80073140[];
extern Blk48_30D80 D_800A4C2C[];
extern void func_8002EFF8(s32 a0, s32 a1);
extern void func_80031988(Ent30D80 *arg0);

void func_80030D80(Ent30D80 *arg0, s16 arg1) {
    u8 old;
    u8 flag;

    old = *(u8 *)&D_800A4F17;
    *(u8 *)&D_800A4F17 = 1;

    if (arg0->unk00 != 0) {
        flag = 1;
        arg0->unk00 = 0;
    } else if (arg0->unk4E >= 2 && (D_800C7D20 & D_80073140[arg0->unk0A])) {
        D_800A4C2C[arg0->unk51].unk41 = 1;
        D_800A4C2C[arg0->unk51].unk00 &= 0xFFF9FFFF;
        flag = 1;
        func_8002EFF8(0, D_80073140[arg0->unk0A]);
    } else {
        flag = 0;
        if (arg1 != 0) {
            arg0->unk50 = 1;
            D_800A4C2C[arg0->unk51].unk41 = 1;
            D_800A4C2C[arg0->unk51].unk00 &= 0xFFF9FFFF;
            func_8002EFF8(0, D_80073140[arg0->unk0A]);
        } else {
            s32 mask = D_80073140[arg0->unk0A];
            arg0->unk50 = 0;
            func_8002EFF8(0, mask);
            func_80031988(arg0);
        }
    }

    if (arg0->unk40 != 0) {
        arg0->unk40(arg0->unk51, arg0->unk44);
    }
    arg0->unk40 = 0;
    if (flag) {
        arg0->unk4E = 0;
    }

    *(u8 *)&D_800A4F17 = old;
}
