/* Exact retail word export for [800331D4,8003324C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_800331D4 - byte-exact against retail at -O2 (tools/register_match.py). */

s32 aF800301A4(void) __asm__("func_800301A4");
extern void func_800301A4(void);
extern s32 func_800331D4(s32);
extern u16 D_800A46E8[];

s32 func_800331D4(s32 arg0) {
    u16 *p;
    register s32 i __asm__("$3");

    p = D_800A46E8;
    i = 0;
    do {
        if ((*p & 0x3F) == 1 && p[2] == (arg0 & 0xFFFF)) {
            if (((u32)arg0 >> 16) == 0 || ((u32)arg0 >> 16) == p[3]) {
                return i + 1;
            }
        }
        i += 1;
        p += 42;
    } while (i < 8);
    return 0;
}
