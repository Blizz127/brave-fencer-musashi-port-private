/* Exact retail word export for [8002E138,8002E5BC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A96E;
extern s32 D_8006A982;
extern s32 D_8006A984;
void func_8002E638(s32);                         /* static */
void func_8002E700(s32);                         /* static */
void func_8002EDE4();                            /* static */
void func_8002EE90(u32);                         /* static */
void func_8002EED8(s32);                         /* static */
void func_8002F0D0(u32);                         /* static */
void func_80031CC8();                            /* static */
extern s8 D_8006A980;
extern s16 D_800A4EE0;
extern s8 D_800A4EE6;
extern s16 D_800A4EF6;
extern s16 D_800A4EFC;
extern s8 D_800A4F1B;
extern s8 D_800A4F1C;
extern s8 D_800A4F1E;

void func_8002E138(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    u32 temp_a0_2;

    temp_a0 = arg0 & 0xFFFF;
    if ((temp_a0 != 0x7F) && (temp_a0_2 = temp_a0 - 1, ((temp_a0_2 < 0x2AU) != 0))) {
        switch (temp_a0) {
        case 1:
            func_8002E638(arg1 & 0xFFFF);
            return;
        case 8:
            func_8002E700(arg1 & 0xFFFF);
            return;
        case 2:
            func_8002F0D0(temp_a0_2);
            func_8002EDE4();
            D_800A4F1B = 1;
            D_800A4EE0 = 0x4000;
            D_800A4F1C = 0;
            D_8006A96E = 0;
            D_8006A980 = 0;
            D_8006A982 = 0;
            D_8006A984 = 0;
            D_800A4EE6 = 0;
            D_800A4EFC = 0x1E;
            D_800A4F1E = 0;
            return;
        case 3:
            func_8002F0D0(temp_a0_2);
            func_80031CC8();
            D_800A4EFC = 0;
            return;
        case 4:
            func_8002EED8((arg1 & 0xFFFF) | (arg2 << 0x10));
            return;
        case 5:
            func_8002EE90(temp_a0_2);
            return;
        case 6:
            D_800A4EF6 = 2;
            return;
        case 7:
            D_800A4EF6 = 1;
            break;
        }
    }
}
