/* sc01_0077: func_80155FF8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
extern void func_80156044(int arg, int a1);
void func_80156044(int param_1, int param_2);

int func_80155FF8(int arg, int a1) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "addiu $sp, $sp, -24\n"
        "sw    $ra, 16($sp)\n"
        "lui   $v0, 0x1f80\n"
        "ori   $v0, $v0, 0x03fc\n"
        "addu  $t0, $v0, $zero\n"
        "lw    $t1, 0($t0)\n"
        "nop\n"
        "sw    $sp, 0($t1)\n"
        "addiu $t1, $t1, -4\n"
        "addu  $sp, $t1, $zero\n"
        "jal   func_80156044\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        "nop\n"
        "lw    $ra, 16($sp)\n"
        "addiu $sp, $sp, 24\n"
        : : : "memory");
}
