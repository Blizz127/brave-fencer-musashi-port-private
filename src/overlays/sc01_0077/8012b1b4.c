/* sc01_0077: func_8012B1B4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_8012B1B4(s32 a0, s32 a1) {
    s32 sp10[4];
    func_800484EC(*(s32 *)(a0 + 0x20) + 0x34, a1, (s32)sp10);
    *(s32 *)(a0 + 0x10) = sp10[0];
    *(s32 *)(a0 + 0x18) = sp10[2];
}
