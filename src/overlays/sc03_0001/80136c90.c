/* sc03_0001: func_80136C90 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef struct { char s[10]; } S10_80136C90;

void func_80136C90()
{
    extern void func_8001534C(int, void *, int, int, int, int);
    extern S10_80136C90 D_801EBEBC;
    S10_80136C90 buf = D_801EBEBC;
    func_8001534C(0, &buf, 0x78, 0x10, 0, 0);
}
