/* sc03_0098: func_8013C9C4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_80019064(void *);
extern s32 D_801C4270;
extern M2C_UNK D_80062BC0;
extern s32 D_801C4270;
extern s8 D_801C4274;
extern s8 D_801C4275;

void func_8013C9C4(void * arg0)
{
    D_801C4270 = arg0;
    D_801C4274 = 0;
    D_801C4275 = 0;
    if (func_80019198() == 0) {
        func_80019064(&D_80062BC0);
    }
}
