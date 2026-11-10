/* sc02_0037: func_80128288 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;

void func_80128288(void) {
    extern u16 D_800B99F6;
    extern void (*D_80183EA4[])(void);
    u32 v1;
    v1 = D_800B99F6;
    if (v1 < 9) {
        D_80183EA4[v1]();
    }
}
