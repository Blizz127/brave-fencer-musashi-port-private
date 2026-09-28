/* Exact retail word export for [80031A98,80031B7C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80031A98 - byte-exact against retail at -O2 (tools/register_match.py). */

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
extern void func_80031A98(void);
struct Ent30D80;
extern s16 D_800C5328[];
extern s16 D_800C532A[];
extern u8  D_800A4988[];
extern u8  D_800A46B0;
extern void func_80030D80(Ent30D80 *arg0, s16 arg1);

void func_80031A98(void)
{
    u8 *p;
    s32 i;
    s32 w;
    u16 h;

    for (p = D_800A4988, i = 0; i < 8; i++, p += 0x54) {
        if (p[0x4E] != 0) {
            if (p[0x36] != 0) {
                w = *(s16 *)((u8 *)D_800C532A + (*(u16 *)(p + 0xE) << 2));
                goto chk;
            }
            h = *(u16 *)(p + 0xE);
            if (h & 0x80) {
                if (D_800A46B0 != 0)
                    func_80030D80((Ent30D80 *)p, 1);
            } else {
                w = *(s16 *)((u8 *)D_800C5328 + (h << 2));
            chk:
                if (w >= 0)
                    continue;
                func_80030D80((Ent30D80 *)p, 1);
            }
        }
    }
}
