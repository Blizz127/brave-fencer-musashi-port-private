/* Overlay range [80173CB4,80173E1C) from MAIN.CD member 0012.
 * SHA256(span)=a921b8969e7e1c609d848b755a5e0409879a303cc0b8dbdfbc27168aeeec7a17.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8013767C(s32);                             /* static */
void func_8014706C(void *);                      /* static */
void func_80147324();                     /* static */
void func_80154274(void *, void *);           /* static */
void func_801553A8(void *);                      /* static */
void func_8016BADC(void *, s32, s32);    /* static */
void func_80171A1C(void *);                      /* static */
s32 func_80171AB0(s16 *);                           /* static */
extern s32 *D_800D5DA8;
extern s32 *D_800D5DB8;
extern void *D_801151D4;
extern u8 D_80126B38;
extern s32 D_8012750C;

void func_80173CB4(void *arg0) {
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s32 var_a0;
    sp10 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x3C);
    sp12 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x40);
    sp14 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x44);
    if ((func_80171AB0(&sp10) << 0x10) == 0) {
        func_8014706C(arg0);
        switch (D_80126B38) {                       /* irregular */
        case 0:
            func_80154274(arg0, &D_800D5DA8);
            M2C_FIELD(arg0, s32 *, 0x200) = 0x20;
            var_a0 = 0x843;
block_13:
            func_80147324(var_a0);
            break;
        case 1:
            func_80154274(arg0, &D_800D5DA8);
block_12:
            func_8016BADC(arg0, -0x40, 0x40);
            M2C_FIELD(arg0, s32 *, 0x200) = 0x80;
            var_a0 = 0x6A6;
            goto block_13;
        case 2:
            func_80154274(arg0, &D_800D5DA8);
            goto block_12;
        case 3:
            func_80154274(arg0, &D_800D5DB8);
            func_801553A8(arg0);
            goto block_12;
        }
        if (D_8012750C != 0) {
            M2C_FIELD(arg0, s32 *, 0x198) = func_8013767C(D_8012750C);
        } else {
            M2C_FIELD(arg0, s32 *, 0x198) = 0;
        }
        func_80171A1C(arg0);
    }
}
