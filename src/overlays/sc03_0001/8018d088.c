/* sc03_0001: func_8018D088 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);

s32 func_8018D088(void *a0)
{
    if (func_8012BD14(*(s32 *)((s32)a0 + 0x64)) > 0x1000) {
        return 0;
    }
    *(s16 *)(*(s32 *)((s32)a0 + 0x64) + 0x2) = 2;
    func_80178BF8();
    return (s32)func_80172710;
}
