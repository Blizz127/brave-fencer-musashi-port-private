/* sc03_0001: func_801727D0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

void func_801727D0(void *a0) {
    extern void (*D_80190A8C[])(void);
    D_80190A8C[*(u8 *)((s32)a0 + 0x214)]();
}
