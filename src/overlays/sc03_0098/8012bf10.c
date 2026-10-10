/* sc03_0098: func_8012BF10 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);

s32 func_8012BF10(s32 a0, s32 a1) {
    s32 v0;
    v0 = *(s32*)(a0 + 0x1C);
    if (v0 == 0) {
        v0 = 1;
    } else {
        v0 -= 1;
        *(s32*)(a0 + 0x1C) = v0;
        v0 = (u32)v0 < 1;
    }
    if (v0 != 0) {
        *(s32*)(a0 + 0x1C) = a1;
        return 1;
    }
    return 0;
}
