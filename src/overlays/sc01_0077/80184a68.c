/* sc01_0077: func_80184A68 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C098(void);
extern void func_8012C098(void);
extern void func_8012C098(void);
void func_80184554(s32 a0);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_8012C044(s32 a0);
extern void func_8012C098(void);

void func_80184A68(s32 param_1)
{
    s32 iVar;
    s32 threshold;
    register s32 cond __asm__("$3");
    if (*(s16 *)(param_1 + 0x70) & 0x8000) {
        iVar = func_8012BCCC(param_1);
        threshold = 0x90000;
    } else {
        iVar = func_8012BCCC(param_1);
        threshold = 0x24000;
    }
    cond = threshold < iVar;
    if (!cond) {
        func_80184554(param_1);
    }
    if (func_8012C044(param_1) != 0) {
        ((void (*)(s32))func_8012C098)(param_1);
    }
}
