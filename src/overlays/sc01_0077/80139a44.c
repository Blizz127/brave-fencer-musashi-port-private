/* sc01_0077: func_80139A44 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80127530[4];

void func_80139A44(s32 a0, u16 a1) {
    if (a1 < 4) {
        D_80127530[a1] = a0;
    }
}
