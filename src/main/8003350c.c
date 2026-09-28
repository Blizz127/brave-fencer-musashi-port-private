/* Exact retail word export for [8003350C,800335B8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8003350C - byte-exact against retail at -O2 (tools/register_match.py). */

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
struct Ent30D80;
extern void func_8003350C(s32, s32);
extern u16 D_800A46E8[];
extern void func_80030D80(Ent30D80 *arg0, s16 arg1);

void func_8003350C(s32 arg0, s32 arg1) {
    register Ent30D80 *p __asm__("$16");
    register s32 t __asm__("$19");
    u8 *base;
    u8 *e;
    s32 off;
    s32 i;

    off = arg0 * 0x54;
    base = (u8 *)D_800A46E8;
    e = base + off;
    i = 0;
    t = arg1 << 16;
    __asm__ ("" :: "r"(t));
    p = (Ent30D80 *)(base + 0x2A0);
    __asm__ ("" :: "r"(base));
    for (; i < 8; i++, p++) {
        u8 *q = e + i;
        if (q[0xE] != 0) {
            q[0xE] = 0;
            p->unk40 = 0;
            if (p->unk4E != 0) {
                func_80030D80(p, t >> 16);
            }
        }
    }
    *(u16 *)e = 0;
}
