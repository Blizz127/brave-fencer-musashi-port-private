/* sc03_0001: func_80180A10 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
s32 func_80180938(void);
extern s32 func_80180938(void);
extern s32 func_80180938(void);
extern s32 func_8012E57C(s32 arg0, s32 arg1);
extern s32 func_80180938(void);

void func_80180A10(void *a0) {
    s32 v0;
    v0 = func_8012E57C(0x61, 0xC);
    *(s32 *)((char *)a0 + 0xCC) = v0;
    v0 = func_80180938();
    if (v0 != 0) {
        v0 = 1;
    } else {
        v0 = 2;
    }
    *(s16 *)((char *)a0 + 0x2) = v0;
}
