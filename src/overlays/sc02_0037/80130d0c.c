/* sc02_0037: func_80130D0C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;

void func_80130D0C(void *a0) {
    extern void (*D_80183F9C[])(void);
    D_80183F9C[*(u8 *)((s32)a0 + 0xC1)]();
}
