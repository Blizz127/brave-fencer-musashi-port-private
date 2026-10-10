/* sc01_0077: func_80130D0C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_80186EAC[])(void *);

void func_80130D0C(void *a0) {
    D_80186EAC[*(u8 *)((s32)a0 + 0xC1)](a0);
}
