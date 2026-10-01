/* Main-exec range [80016D78,80016EB0) from the SLUS executable.
 * SHA256(span)=3c2cb12f2f0c76b22b82a64745099d7259362364906afc0204e5f50a182c6226.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                       /* static */
void func_80017E8C();                     /* static */
void func_80018194(void *, s32, u32);            /* static */
s32 func_8004958C(void *, void *, void *, void *, void *, void *, void *, s32 *); /* static */
s16 func_80058B40(s32, s32, s32, s32);          /* static */
s16 func_80058B7C(s32, s32);                    /* static */
void func_80058D84(void *);                      /* static */

void func_80016D78(void *arg0, s32 arg1) {
    s32 sp24;
    s32 sp20;
    s32 var_a0;
    s32 temp_v0_2;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u8 temp_a1;
    void *temp_v0;

    temp_v0 = func_80010A08(0x20);
    (*(s32 *) ((s8 *) (temp_v0) + (4))) = (s32) (*(s32 *) ((s8 *) (arg0) + (0x24)));
    func_80058D84(temp_v0);
    func_80017E8C(arg1);
    temp_v0_2 = func_8004958C(arg0, arg0 + 8, arg0 + 0x10, temp_v0 + 8, temp_v0 + 0x10, temp_v0 + 0x18, &sp20, &sp24);
    temp_v1 = (*(u32 *) ((s8 *) (arg0) + (0x18)));
    (*(s8 *) ((s8 *) (temp_v0) + (0xC))) = (s8) temp_v1;
    (*(s8 *) ((s8 *) (temp_v0) + (0xD))) = (s8) (temp_v1 >> 0x10);
    temp_v1_2 = (*(u32 *) ((s8 *) (arg0) + (0x1C)));
    (*(s8 *) ((s8 *) (temp_v0) + (0x14))) = (s8) temp_v1_2;
    (*(s8 *) ((s8 *) (temp_v0) + (0x15))) = (s8) (temp_v1_2 >> 0x10);
    temp_v1_3 = (*(u32 *) ((s8 *) (arg0) + (0x20)));
    (*(s8 *) ((s8 *) (temp_v0) + (0x1C))) = (s8) temp_v1_3;
    (*(s8 *) ((s8 *) (temp_v0) + (0x1D))) = (s8) (temp_v1_3 >> 0x10);
    (*(s16 *) ((s8 *) (temp_v0) + (0x16))) = func_80058B40(0, ((u32) (*(u32 *) ((s8 *) (arg0) + (0x28))) >> 0x1C) & 3, ((u16) (*(u32 *) ((s8 *) (arg0) + (0x18))) >> 2) & 0x3FC0, (*(u16 *) ((s8 *) (arg0) + (0x1A))) & 0xFF00);
    temp_a1 = (*(u8 *) ((s8 *) (arg0) + (0x2C)));
    var_a0 = 0x100;
    if (temp_a1 < 0xE0U) {
        var_a0 = 0x160;
    }
    (*(s16 *) ((s8 *) (temp_v0) + (0xE))) = func_80058B7C(var_a0, temp_a1 | 0x100);
    if (!(sp24 & ~0x1000)) {
        func_80018194(temp_v0, temp_v0_2, (*(u32 *) ((s8 *) (arg0) + (0x28))));
    }
}
