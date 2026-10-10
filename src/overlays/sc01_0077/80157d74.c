/* sc01_0077: func_80157D74 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
extern void func_80157DC4(void *a0);
extern void func_80157FC4(void *a0);
void func_80157DC4(void *a0);
void func_80157FC4(void *a0);

void func_80157D74(u16 *a0) {
    switch (a0[0]) {
    case 0x24:
        func_80157DC4(a0);
        break;
    case 0x25:
        func_80157FC4(a0);
        break;
    }
}
