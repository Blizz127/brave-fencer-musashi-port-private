/* sc02_0037: func_8012EF70 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012EFB8(s32 a0);
extern void func_8012EFB8(s32 a0);

void func_8012EF70(s32 a0, s32 a1) {
    s32 sp10;
    register s32 v1 __asm__("$3");
    func_8012EFB8(a0);
    {
        register s32 *p __asm__("$3") = &sp10;
        __asm__ __volatile__(
            "mfc2 $12, $19\n"
            "nop\n"
            "sra $12, $12, 2\n"
            "sw $12, 0(%0)\n"
            : : "r"(p) : "memory", "$12");
    }
    v1 = sp10;
    *(s16 *)(a1 + 4) = v1;
}
