/* sc01_0077: func_80179D30 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80178D40.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
extern void func_8012A568(void (*a0)(void));
void func_80179B74(u16 *p);
extern void func_80179B74(u16 *p);

void func_80179D30(u16 *a0) {
    s16 buf[4];
    buf[0] = 1;
    buf[1] = a0[0];
    buf[2] = a0[1];
    buf[3] = a0[2];
    func_80179B74(buf);
}
