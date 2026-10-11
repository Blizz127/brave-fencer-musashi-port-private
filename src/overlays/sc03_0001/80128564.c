/* sc03_0001: func_80128564 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s16 D_800B9A08;
extern void func_80178608(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80011A3C(void);
extern short D_800B9A08;
extern short D_800B99F2;

void func_80128564(void) {
    s32 p = 0x1F8003FC;
    __asm__ __volatile__(
        "addu  $8, %0, $zero\n"
        "sw    $sp, 0($8)\n"
        "addiu $8, $8, -4\n"
        "addu  $sp, $8, $zero\n"
        "jal   func_80178608\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : : "r"(p) : "$8", "memory");
    if (D_800B9A08 == 0x300A) {
        func_8002D4C8(6, 0);
    }
    func_80011A3C();
    D_800B99F2 = 1;
}
