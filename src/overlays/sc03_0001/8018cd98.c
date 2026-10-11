/* sc03_0001: func_8018CD98 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
void func_8018CBB0(s32 param_1, s32 param_2);
extern void func_8018CBB0(s32, s32);
extern s32 func_8012BEE8(s32 a0);
extern void func_8018CBB0(s32, s32);

void func_8018CD98(s32 arg0) {
    if (func_8012BEE8(arg0)) {
        *(s32 *)(arg0 + 0x1c) = (s32)*(s16 *)(arg0 + 0xfe);
        func_8018CBB0(arg0, 0x110);
    }
}
