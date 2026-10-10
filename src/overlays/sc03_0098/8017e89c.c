/* sc03_0098: func_8017E89C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void (*D_80188F4C[])(void);

void func_8017E89C(void *a0) {
    D_80188F4C[*(u8 *)((s32)a0 + 0x15)]();
}
