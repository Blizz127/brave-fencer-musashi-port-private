/* sc03_0098: func_80136BC4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80136BC4(s32 a0) {
    if (*(s32*)(a0 + 0x8) == 0x20) {
        *(s32*)(a0 + 0x8) = a0 + 0x20;
        *(s32*)(a0 + 0xC) += a0;
        *(s32*)(a0 + 0x10) += a0;
        *(s32*)(a0 + 0x14) += a0;
        *(s32*)(a0 + 0x18) += a0;
        *(s32*)(a0 + 0x1C) += a0;
    }
}
