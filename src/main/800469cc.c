/* Exact retail word export [800469CC,80046A5C); verified against pinned EXE and asm. */
#include "psx_types.h"

/* Decompiled by hand from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

typedef struct { u32 w; } __attribute__((packed)) U32_800469CC;
extern s32 D_800C6D3C;
extern s32 D_800C7C94;
extern s32 D_800C6D38;
extern void (*D_800A5E80)(void);
extern u8 D_80078800[];
extern s32 D_80078804;
extern s32 D_800AE644;

/* Mixed-alignment views over one computed base: the `s16` store and
 * the `+8` word load go through plain types (`sh`, `lw`), while the
 * `+0x1C` word copy goes through packed `u32` (`lwl`/`swl`). All
 * three share one base register. The callback takes no arguments
 * (m2c's two-arg guess would emit setups retail lacks). */
void func_800469CC(void) {
    s32 i = D_800C6D3C;
    s32 base = D_800C7C94;
    u8 *pu = (u8 *)base + (i << 5);
    s32 *p32 = (s32 *)pu;
    u8 *a2 = &D_80078800[0];

    *(s16 *)pu = 2;
    *(U32_800469CC *)a2 = *(U32_800469CC *)(pu + 0x1C);
    {
        s32 x = p32[2];
        D_80078804 = x;
    }
    D_800C6D3C = D_800C6D38;
    if (D_800A5E80 != 0) {
        D_800A5E80();
    }
    D_800AE644 = 0;
}
