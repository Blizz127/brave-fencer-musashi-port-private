/* sc01_0077: func_8013F1BC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
extern unsigned short D_80115112;
extern unsigned short D_80115112;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern u16 D_80115112;
extern unsigned short D_80115118;
extern unsigned short D_80115112;
extern void func_800D2624(void);
extern short D_800B9A02;
extern unsigned short D_80115114;
extern unsigned short D_80115112;
extern unsigned short D_80115118;

void func_8013F1BC(void) {
    unsigned short *p = &D_80115118;
    if (*p != 0) {
        *p -= 0x10;
        __asm__ __volatile__("" ::: "memory");
        if (*p != 0) {
            return;
        }
    }
    if (D_80115114 == ((unsigned short)D_800B9A02 ^ 1)) {
        func_800D2624();
    } else {
        D_80115112 += 1;
    }
}
