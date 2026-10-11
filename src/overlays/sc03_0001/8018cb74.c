/* sc03_0001: func_8018CB74 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void (*D_801EB364[])(void);

void func_8018CB74(void *a0) {
    D_801EB364[*(u16 *)((s32)a0 + 0x2)]();
}
