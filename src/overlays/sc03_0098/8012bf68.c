/* sc03_0098: func_8012BF68 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012BF68(void *a0) {
    *(u16 *)((s32)a0 + 0x5C) &= 0x7FFF;
}
