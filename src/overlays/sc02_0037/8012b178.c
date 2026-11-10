/* sc02_0037: func_8012B178 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_8012B178(s32 a0, s32 a1) {
    s32 sp10[3];
    sp10[2] = a1;
    sp10[1] = 0;
    sp10[0] = 0;
    func_800484EC(*(s32 *)(a0 + 0x20) + 0x34, (s32)sp10, a0 + 0x10);
}
