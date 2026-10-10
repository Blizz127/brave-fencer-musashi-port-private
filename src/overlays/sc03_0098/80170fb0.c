/* sc03_0098: func_80170FB0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void (*D_80188868[])(void);

void func_80170FB0(void *a0) {
    D_80188868[*(u8 *)((s32)a0 + 0x216)]();
}
