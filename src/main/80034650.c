/* Exact retail word export for [80034650,800346D0); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80034650 - byte-exact against retail at -O2 (tools/register_match.py). */

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
struct Ent30D80;
extern void func_80034650(u8 *, s32);
extern u8 D_800A4988[];
void func_80030D80(Ent30D80 *arg0, s16 arg1);

void func_80034650(u8 *param_1, s32 param_2)
{
    s32 i;
    s32 pm;

    pm = (param_2 & 0xFF) << 16;
    for (i = 0; i < 8; i++) {
        if (*(param_1 + i + 0x3A) != 0) {
            func_80030D80((Ent30D80 *)(D_800A4988 + i * 0x54), pm >> 16);
        }
    }
    *(u16 *)param_1 = 0;
}
