/* Exact retail word export [8001C0C8,8001C14C); verified against pinned EXE and asm. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference. */
/* func_8001C0C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern void func_80016714(void *a0, s32 a1);
extern u8 D_800AF630[];

void func_8001C0C8(void) {
    u8 *base;
    u8 *p;
    s32 i;

    base = D_800AF630;
    p = &base[0x65A8];
    i = 0;
    do {
        func_80016714(p, 0x38);
        i++;
        p += 0x38;
    } while (i < 0x100);

    p = &base[0x2A8];
    i = 0;
    do {
        func_80016714(p, 0x84);
        i++;
        p += 0x84;
    } while (i < 0xC0);

    *(u16 *)&base[0x19C] = 0;
}
