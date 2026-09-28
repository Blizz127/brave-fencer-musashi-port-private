/* Exact retail word export for [800346D0,800347C8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_800346D0 - byte-exact against retail at -O2 (tools/register_match.py). */

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
extern void func_800346D0(s32);
struct Ent30D80;
typedef struct {
    u8 pad[0x3A];
    u8 flg[8];
    u8 tail[0x12];
} S54;
extern u16 D_800A46E8[];
extern void func_80030D80(Ent30D80 *arg0, s16 arg1);

void func_800346D0(s32 arg0) {
    S54 *p;
    S54 *q;
    Ent30D80 *e;
    Ent30D80 *ebase;
    s32 i;
    s32 j;
    s32 lo;
    s32 hi;

    p = (S54 *)D_800A46E8;
    i = 0;
    lo = (arg0 << 16) >> 16;
    hi = arg0 >> 16;
    ebase = (Ent30D80 *)((u8 *)D_800A46E8 + 0x2A0);
    q = (S54 *)((u8 *)D_800A46E8 + 6);
    do {
        if (*(u16 *)p == 5 && *((u16 *)q - 1) == lo && (hi == 0 || hi == *(u16 *)q)) {
            j = 0;
            e = ebase;
            do {
                if (p->flg[j] != 0) {
                    func_80030D80(e, 0);
                }
                j++;
                e++;
            } while (j < 8);
            *(u16 *)p = 0;
        }
        i++;
        q++;
        p++;
    } while (i < 8);
}
