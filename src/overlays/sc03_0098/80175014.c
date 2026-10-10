/* sc03_0098: func_80175014 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

s32 func_80175014(u8 *a0, u8 *a1, s32 a2) {
    a2 = (s16)a2;
    a1 = a1 + a2 * 14;
    if (*(s16 *)(a1 + 0xC) == 0x7FFF) {
        return 1;
    }
    *(s32 *)(a0 + 0x3C) = *(s16 *)(a1 + 0);
    *(s32 *)(a0 + 0x40) = *(s16 *)(a1 + 2);
    *(s32 *)(a0 + 0x44) = *(s16 *)(a1 + 4);
    *(s32 *)(a0 + 0x48) = *(s16 *)(a1 + 6);
    *(s32 *)(a0 + 0x4C) = *(s16 *)(a1 + 8);
    *(s32 *)(a0 + 0x50) = *(s16 *)(a1 + 0xA);
    *(s32 *)(a0 + 0x54) = *(s16 *)(a1 + 0xC) << 5;
    return 0;
}
