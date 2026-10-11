/* sc03_0001: func_8013C9C4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_80019064(void *);
extern s32 D_801ED428;
extern M2C_UNK D_80062BC0;
extern s32 D_801ED428;
extern s8 D_801ED42C;
extern s8 D_801ED42D;

void func_8013C9C4(void * arg0)
{
    D_801ED428 = arg0;
    D_801ED42C = 0;
    D_801ED42D = 0;
    if (func_80019198() == 0) {
        func_80019064(&D_80062BC0);
    }
}
