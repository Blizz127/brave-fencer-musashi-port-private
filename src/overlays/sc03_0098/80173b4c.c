/* sc03_0098: func_80173B4C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void (*D_80188940[])(void *);

void func_80173B4C(void *a0) {
    D_80188940[*(u8 *)((s32)a0 + 0x214)](a0);
}
