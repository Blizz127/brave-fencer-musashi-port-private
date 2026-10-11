/* sc03_0001: func_80181800 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
s32 func_801816D8(void);
extern s32 func_801816D8();
extern u8 D_801EF3D6;

void func_80181800(s32 a0) {
    if (func_801816D8() != 0) {
        *(s32 *)(*(s32 *)(a0 + 0xCC) + 0xB0) = 1;
        D_801EF3D6 = 1;
    } else {
        *(s32 *)(*(s32 *)(a0 + 0xCC) + 0xB0) = 2;
        D_801EF3D6 = 0;
    }
}
