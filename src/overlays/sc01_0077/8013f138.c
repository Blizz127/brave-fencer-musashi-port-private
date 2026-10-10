/* sc01_0077: func_8013F138 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
extern u16 D_80115110;
extern unsigned short D_80115112;
extern unsigned short D_80115112;
extern u16 D_80115110;
extern unsigned short D_80115112;
extern unsigned short D_80115112;
extern void func_801376E8(int a0, int a1);
extern unsigned char *func_80141CA4(void);
extern unsigned short D_80115112;
extern unsigned char D_80187E98;
extern u16 D_80115112;
extern unsigned short D_80115118;
extern unsigned short D_80115112;
extern u16 D_80115110;
extern unsigned char D_80187E98;
extern unsigned char *func_80141CA4(void);
extern void func_801376E8(int a0, int a1);
unsigned char *func_80141CA4(void);

void func_8013F138(void) {
    u16 *p = &D_80115118;
    *p += 0x10;
    if ((u16)*p >= 0x40) {
        if (D_80115110 == 0) {
            ((void (*)(int, unsigned char *))func_801376E8)((int)func_80141CA4(), &D_80187E98);
        }
        D_80115112 += 1;
    }
}
