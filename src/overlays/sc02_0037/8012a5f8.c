/* sc02_0037: func_8012A5F8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A62C(s32);
void func_8012A62C(s32 a0);

void func_8012A5F8(void (*a0)(void), s32 a1) {
    func_8012A62C(a1 & 0xFF);
    a0();
}
