/* sc01_0077: func_80180898 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(int, int);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80180898(void *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    temp_v0 = (*(s16 *)((s8 *)(arg0) + (0xFC)));
    if (temp_v0 != 0) {
        temp_v0_2 = temp_v0 - 1;
        (*(s16 *)((s8 *)(arg0) + (0xFC))) = temp_v0_2;
        if ((temp_v0_2 << 0x10) == 0) {
            func_8002D4C8(0xD, 0x401);
        }
    }
}
