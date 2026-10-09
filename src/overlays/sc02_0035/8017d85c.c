/* SC02.CD member35: func_8017D85C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);

void func_8017D85C(s32 a0) {
    if (*(s16 *)(a0 + 0x108) != 0) {
        *(s16 *)(a0 + 0x108) = *(s16 *)(a0 + 0x108) - 1;
        return;
    }
    *(u16 *)(a0 + 0x106) = *(u16 *)(a0 + 0x106) + *(u16 *)(a0 + 0xFE);
    *(s16 *)(a0 + 0x6) = *(u16 *)(a0 + 0x88) +
        ((func_8004787C(*(s16 *)(a0 + 0x106)) * *(s16 *)(a0 + 0x104)) >> 12);
    *(s16 *)(a0 + 0xA) = *(u16 *)(a0 + 0x8A) +
        ((func_80047948(*(s16 *)(a0 + 0x106)) * *(s16 *)(a0 + 0x104)) >> 12);
    if ((*(u16 *)(a0 + 0x106) & 0x7FF) == 0) {
        *(s16 *)(a0 + 0x108) = 0xF;
    }
}
