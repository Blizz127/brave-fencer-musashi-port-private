/* Exact retail word export for [800383A4,800384A8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800383A4 - byte-exact against retail at -O2 (tools/register_match.py). */


extern u8 D_800B9CD8[];
extern u8 D_800A4F1D;
extern u8 D_800C6E2D[];
extern s32 D_80073140[][1];  /* [][1] spelling: load-bearing for func_800391D4 (S79 lever; §500-I) */
extern void func_8003916C(s16 arg0);
extern void func_8002EFF8(s32 a0, s32 a1);

void func_800383A4(a0)
    s16 a0;
{
    u8 *base;
    u8 *p;
    u8 *q;
    u8 *r;
    s32 *t;
    s32 *table;
    s32 i;
    s32 j;
    s32 one;
    register s32 aa __asm__("$2");

    __asm__("sll %0, %1, 7\n\tsubu %0, %0, %1\n\tsll %0, %0, 2" : "=r"(aa) : "r"(a0));
    base = &D_800B9CD8[aa];
    p = base + 0x1A;
    i = 0;
    one = 1;
    table = (s32 *)D_80073140;
    D_800A4F1D = 1;
    base[0x1FA] = 0;
    do {
        q = p + 9;
        j = 0;
        r = D_800C6E2D;
        t = table;
        do {
            if (*q++ != 0) {
                r[1] = one;
                r[0] = 0;
                func_8003916C((s16)j);
                func_8002EFF8(0, *t);
            }
            t++;
            j++;
            r += 0x60;
        } while (j < 0x10);
        i++;
        p += 0x1A;
    } while (i < 0x10);
    D_800A4F1D = 0;
}
