/* sc01_0077: func_801844F4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32, s32);
M2C_UNK func_8002AC00(M2C_UNK);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_801844F4(void *arg0) {
    M2C_UNK var_a0;
    M2C_UNK var_a0_2;
    var_a0 = 2;
    if ((*(u16 *)((s8 *)(arg0) + (0x70))) & 1) {
        var_a0 = 8;
    }
    func_8002AC00(var_a0);
    var_a0_2 = 0x43F;
    if ((*(u16 *)((s8 *)(arg0) + (0x5E))) == 0x1D) {
        var_a0_2 = 0x440;
    }
    func_8002D4C8(var_a0_2, 0);
}
