/* sc03_0001: func_801803DC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012B414(int a0);

void func_801803DC(s32 arg0) {
        s32 temp_v1 = *(s32 *)(arg0 + 0x20);
        *(s16 *)(temp_v1 + 0x14) += 0x8;
        ((void (*)(void))func_8012B414)();
    }
