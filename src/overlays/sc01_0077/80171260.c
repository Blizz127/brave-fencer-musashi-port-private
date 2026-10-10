/* sc01_0077: func_80171260 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 (*D_8018A084[])(void *);

s32 func_80171260(void *a0) {
    return D_8018A084[*(u8 *)((s32)a0 + 0x216)](a0);
}
