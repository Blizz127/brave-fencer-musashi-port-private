/* sc03_0001: func_8018828C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
s32 func_80187C2C(s32 a0);
extern void func_8018835C(s32 a0);
extern void func_8018835C(s32 a0);
extern s32 func_80187C2C(s32 a0);
extern void func_8012E688(s32 param_1, u16 param_2, u16 param_3);
extern s32 func_801889AC(void);
extern s32 func_801889AC(void);
extern s32 func_80187C2C(s32 a0);
extern void func_8018835C(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012E688(s32 param_1, u16 param_2, u16 param_3);
extern s32 func_801889AC(void);
void func_8018835C();

void func_8018828C(s32 a0) {
    if (func_80187C2C(a0) == 2) {
        func_8018835C(a0);
    }
    if (*(u16 *)(a0 + 0x34) == 0) {
        if (func_8012BEE8(a0) == 0) {
            return;
        }
        *(u16 *)(a0 + 0x34) = 1;
    }
    *(u16 *)(a0 + 0x100) = *(u16 *)(a0 + 0x100) + *(u16 *)(a0 + 0x102);
    if (*(s16 *)(a0 + 0x100) >= 0x50) {
        *(u16 *)(a0 + 0x100) = 0x50;
    }
    *(u16 *)(a0 + 0xFE) = *(u16 *)(a0 + 0xFE) - *(u16 *)(a0 + 0x100);
    if (*(s16 *)(a0 + 0xFE) <= 0) {
        func_8012E688(a0, 0x515, 0);
        func_8018835C(a0);
    } else {
        ((void (*)(s32))func_801889AC)(a0);
    }
}
