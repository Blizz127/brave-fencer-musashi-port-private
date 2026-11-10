/* sc02_0037: func_801657A0 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
extern void func_801657D8(void);
extern u8 D_80078EC3;
void func_801657D8(void);

void func_801657A0(void) {
    if (D_80078EC3 == 0) {
        D_80078EC3 = 1;
        func_801657D8();
    }
}
