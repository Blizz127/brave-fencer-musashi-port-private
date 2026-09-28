/* Exact retail word export for [80034A9C,80034AE0); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80034A9C - byte-exact against retail at -O2 (tools/register_match.py). */

s32 aF800301A4(void) __asm__("func_800301A4");
extern void func_800301A4(void);
extern s8 D_800A4F17;

void func_80034A9C(void *a0) {
    register void *a1 __asm__("$5") = a0;
    u8 *v1;
    u8 old;

    if (*(u16 *)((u8 *)a1 + 0x30) == 0x3FFF) {
        return;
    }
    v1 = (u8 *)&D_800A4F17;
    old = *v1;
    *v1 = 1;
    *(s8 *)((u8 *)a1 + 0x32) = 1;
    *(s16 *)((u8 *)a1 + 0x2E) = 0x3FF;
    *(s16 *)((u8 *)a1 + 0x30) = 0x3FFF;
    *v1 = old;
}
