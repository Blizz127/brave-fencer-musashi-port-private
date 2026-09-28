/* Exact retail word export for [8003491C,80034A54); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8003491C - byte-exact against retail at -O2 (tools/register_match.py). */

extern void func_8003491C(s32 arg0);
s32 aF800301A4(void) __asm__("func_800301A4");
extern void func_800301A4(void);
extern u8 D_8006451C[];
extern s8 D_800A4F17;
extern s32 func_8002F4E4(u8 *);

void func_8003491C(s32 arg0)
{
    register s32 zr __asm__("$0");
    s32 id;
    s32 raw;
    s32 t;
    s16 lo;
    s16 hi;
    u8 *p;
    u8 old;
    u8 *e;
    s32 i;

    id = arg0 + zr;
    lo = (s16)arg0;
    p = &D_8006451C[lo * 4];
    hi = (s16)((u32)arg0 >> 16);
    if ((*p & 0x7F) == 6) {
        raw = func_8002F4E4(p);
        t = (s16)raw;
        id = raw + zr;
        if (t == 0) {
            return;
        }
        p = &D_8006451C[t * 4];
    }
    if ((s16)id < 0x100) {
        return;
    }
    old = *(u8 *)&D_800A4F17;
    *(u8 *)&D_800A4F17 = 1;
    if ((*p & 0x7F) != 1 && (*p & 0x7F) == 5) {
        e = (u8 *)&D_800A4F17 - 0x82F;
        for (i = 0; i < 8; i++, e += 0x54) {
            if (*(u16 *)e == 5 && *(u16 *)(e + 4) == lo) {
                if (hi == 0 || hi == *(u16 *)(e + 6)) {
                    e[0x16] = 1;
                }
            }
        }
    }
    *(u8 *)&D_800A4F17 = old;
}
