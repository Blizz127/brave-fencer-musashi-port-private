/* sc03_0098: func_8015640C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 arg);
extern s32 func_801564B0(s32 a0);
extern s32 func_80029178(s32 a0);
s32 func_801564B0(s32 a0);

s32 func_8015640C(s32 a0, s32 a1) {
    if ((func_801564B0(a0) & 0xFFFF) != 0) {
        if ((func_80029178(0x1C) & 0xFF) != 0) {
            return (((175 * (a1 & 0xFFFF)) / 100) & 0xFFFF) | 0x8000;
        } else {
            return (((150 * (a1 & 0xFFFF)) / 100) & 0xFFFF) | 0x8000;
        }
    }
    return a1 & 0xFFFF;
}
