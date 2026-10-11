/* sc03_0001: func_801657A0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
