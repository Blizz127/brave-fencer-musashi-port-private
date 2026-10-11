/* sc03_0001: func_801751D8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80146CA0(void *a0);
extern s32 func_80161104(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80161104(void);
extern s32 func_80175218(void *a0);
extern void func_80146CA0(void *a0);
s32 func_80175218(void * param_1);

void func_801751D8(void *a0) {
    void *s = a0;
    if (func_80161104()) {
        func_80175218(s);
        func_80146CA0(s);
    }
}
