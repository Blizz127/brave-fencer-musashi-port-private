/* sc01_0077: func_8012AD44 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012AD44(s32 *a0, s16 a1) {
    *(s16*)((s32)a0 + 0x2) = a1;
    *(s16*)((s32)a0 + 0x34) = 0;
}
