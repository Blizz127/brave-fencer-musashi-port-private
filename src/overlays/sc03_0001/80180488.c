/* sc03_0001: func_80180488 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);

void func_80180488(s32 arg0)
{
    extern u16 D_800B99DA;
    extern s32 func_8004787C(s32 a0);
    *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x10) = (u32)func_8004787C(D_800B99DA * 48) >> 5;
}
