/* sc03_0001: func_801801E0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012E8E0(s32 a0, s32 a1);
extern u8 D_80191904[];
extern void func_8012E8E0(s32 a0, s32 a1);

void func_801801E0(s32 a0) {
        *(s16 *)(a0 + 0x2) = 1;
        func_8012E8E0(a0, (s32)&D_80191904);
        *(s16 *)(a0 + 0xFE) = 0;
        *(s16 *)(a0 + 0xFC) = 0x80;
    }
