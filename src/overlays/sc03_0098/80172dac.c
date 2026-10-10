/* sc03_0098: func_80172DAC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

s32 func_80172DAC(void *a0) {
    extern void (*D_801888E0[])(void);
    D_801888E0[*(u8 *)((s32)a0 + 0x214)]();
}
