/* sc02_0037: func_8013C9C4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80019064(void *);
extern void func_80019064(void *a0);
extern void func_80019064(void *a0);

void func_8013C9C4(void * arg0)
{
    extern M2C_UNK D_80062BC0;
    extern s32 D_801C8490;
    extern s8 D_801C8494;
    extern s8 D_801C8495;
    D_801C8490 = arg0;
    D_801C8494 = 0;
    D_801C8495 = 0;
    if (func_80019198() == 0) {
        func_80019064(&D_80062BC0);
    }
}
