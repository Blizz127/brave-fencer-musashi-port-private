/* sc02_0037: func_8012B14C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_8012B14C(s32 a0, s32 a1) {
    func_800484EC(*(s32 *)((s32)a0 + 0x20) + 0x34, a1, (s32)a0 + 0x10);
}
