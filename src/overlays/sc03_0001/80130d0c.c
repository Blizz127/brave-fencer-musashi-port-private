/* sc03_0001: func_80130D0C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_8018D89C[])(void);

void func_80130D0C(void *a0) {
    D_8018D89C[*(u8 *)((s32)a0 + 0xC1)]();
}
