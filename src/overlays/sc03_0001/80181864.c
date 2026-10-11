/* sc03_0001: func_80181864 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 arg0, s32 arg1);
extern s32 func_8012E57C(s32 a0, s32 a1);
s32 func_801816D8(void);
extern s32 func_801816D8();
extern u8 D_801EF3D6;
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_801816D8();
extern u8 D_801EF3D6;

void func_80181864(s32 a0) {
    *(s16 *)(a0 + 0x2) = 1;
    *(s32 *)(a0 + 0xCC) = func_8012E57C(0x61, 0xE);
    if (func_801816D8() != 0) {
        *(s32 *)(*(s32 *)(a0 + 0xCC) + 0xB0) = 1;
        D_801EF3D6 = 1;
    } else {
        *(s32 *)(*(s32 *)(a0 + 0xCC) + 0xB0) = 2;
        D_801EF3D6 = 0;
    }
}
