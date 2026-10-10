/* sc03_0098: func_8017D5DC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void (*D_80188E9C[])(void);

void func_8017D5DC(void *a0) {
    D_80188E9C[*(u16 *)((s32)a0 + 0x2)]();
}
