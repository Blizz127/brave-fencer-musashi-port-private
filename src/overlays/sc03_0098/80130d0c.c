/* sc03_0098: func_80130D0C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_801856B0[])(void *);

void func_80130D0C(void *a0) {
    D_801856B0[*(u8 *)((s32)a0 + 0xC1)](a0);
}
