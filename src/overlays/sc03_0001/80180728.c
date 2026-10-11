/* sc03_0001: func_80180728 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
s32 func_80180634(void);
extern s32 func_80180634(void);
extern s32 func_8012E57C(s32 a0, s32 a1);

void func_80180728(void *a0) {
    s32 v0;
    v0 = func_8012E57C(0x61, 0xD);
    *(s32 *)((char *)a0 + 0xCC) = v0;
    v0 = func_80180634();
    if (v0 != 0) {
        v0 = 2;
    } else {
        v0 = 1;
    }
    *(s16 *)((char *)a0 + 0x2) = v0;
}
