/* sc03_0001: func_8017496C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

s32 func_8017496C(void *a0) {
    extern void (*D_80190B80[])(void);
    D_80190B80[*(u8 *)((s32)a0 + 0x4)]();
}
