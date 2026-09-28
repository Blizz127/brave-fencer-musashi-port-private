/* Exact retail word export for [80030CA4,80030D80); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80030CA4 - byte-exact against retail at -O2 (tools/register_match.py). */

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
s32 aF800301A4(void) __asm__("func_800301A4");
extern void func_800301A4(void);
extern u8 D_800A4988[];
extern void func_80030D80(Ent30D80 *arg0, s16 arg1);
extern s32 func_80030CA4(u16);

s32 func_80030CA4(u16 arg0)
{
    u8 *base;
    u8 *p;
    register s32 i __asm__("$6");
    register s32 one __asm__("$7");
    s32 besti;
    u8 *bestp;
    u16 best;
    u8 first;

    (void)&besti;
    (void)&bestp;
    (void)&best;
    (void)&first;

    base = D_800A4988;
    i = 0;
    one = 1;
    p = base + 8;
    first = 0;

    for (; i < 8; i++, p += 0x54, base += 0x54) {
        if (p[0x46] == 0) {
            return i + 1;
        }
        if (first == 0) {
            best = *(u16 *)p;
            first = (u8)one;
            besti = i;
            bestp = base;
        } else if (*(u16 *)p < best) {
            best = *(u16 *)p;
            besti = i;
            bestp = base;
        }
    }

    if ((u16)arg0 < best) {
        return 0;
    }

    func_80030D80((Ent30D80 *)bestp, 1);
    *(u8 *)(base + 0x4E) = 0;
    besti = besti + 1;
    return besti;
}
