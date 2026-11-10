/* sc02_0037: func_80136C90 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80135EB0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef struct { char s[10]; } S10_80136C90;

s32 func_80136C90()
{
    extern void func_8001534C(int, void *, int, int, int, int);
    extern S10_80136C90 D_801C7454;
    S10_80136C90 buf = D_801C7454;
    func_8001534C(0, &buf, 0x78, 0x10, 0, 0);
}
