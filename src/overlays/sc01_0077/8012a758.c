/* sc01_0077: func_8012A758 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_a.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_8012A7D4(void *a0, void *a1);
extern void func_8012A7D4(void *a0, void *a1);
extern s16 func_8012A79C(s16 *a0, s16 *a1);
s16 func_8012A79C(s16 *a0, s16 *a1);
void func_8012A7D4(void *arg0, void *arg1);

s16 func_8012A758(void) {
    s16 a[4];
    s16 b[4];
    func_8012A7D4(a, b);
    return func_8012A79C(a, b);
}
