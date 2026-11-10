/* sc02_0037: func_8012DB84 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern void func_8014C978(void);
void func_8012F568(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6);

s32 func_8012DB84(void)
{
    extern M2C_UNK D_80183F50;
    extern M2C_UNK D_80183F58;
    func_8014C978();
    func_8012F568(1, 0xC001, 0, 0x3E8, &D_80183F50, &D_80183F58);
}
