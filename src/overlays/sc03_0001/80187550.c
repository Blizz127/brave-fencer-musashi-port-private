/* sc03_0001: func_80187550 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
s32 func_80187420(s32 a0);
extern s32 func_80187420(s32 arg);
extern void func_80187584(void *a0);
void func_80187584(void *a0);

void func_80187550(void *a0) {
    *(s32 *)((char *)a0 + 0xe0) = func_80187420((s32)a0);
    func_80187584(a0);
}
