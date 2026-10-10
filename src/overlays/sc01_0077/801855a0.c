/* sc01_0077: func_801855A0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void (*D_801B12A4[])(void);

void func_801855A0(void *a0) {
    D_801B12A4[*(u16 *)((s32)a0 + 0x2)]();
}
