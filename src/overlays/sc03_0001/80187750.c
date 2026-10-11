/* sc03_0001: func_80187750 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

void func_80187750(s32 a0)
{
    extern s32 D_801C0B08;
    *(s32 *)(a0 + 0x58) = (u32)&D_801C0B08 | 0x40000000;
    *(s16 *)(a0 + 0x5C) = 0x800;
}
