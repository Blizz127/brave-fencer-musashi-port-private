/* sc03_0098: func_8017509C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

s32 func_8017509C(u8 *a0, s32 a1, u8 *a2, u8 *a3) {
    a1 = (s16)a1;
    a0 = a0 + a1 * 14;
    if (*(s16 *)(a0 + 0xC) == 0x7FFF) {
        return 1;
    }
    *(u16 *)(a2 + 0) = *(u16 *)(a0 + 0);
    *(u16 *)(a2 + 2) = *(u16 *)(a0 + 2);
    *(u16 *)(a2 + 4) = *(u16 *)(a0 + 4);
    *(u16 *)(a3 + 0) = *(u16 *)(a0 + 6);
    *(u16 *)(a3 + 2) = *(u16 *)(a0 + 8);
    *(u16 *)(a3 + 4) = *(u16 *)(a0 + 0xA);
    return 0;
}
