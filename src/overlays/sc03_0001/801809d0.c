/* sc03_0001: func_801809D0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
s32 func_80180938(void);
extern s32 func_80180938(void);
extern s32 func_80180938(void);

void func_801809D0(s32 a0) {
    s32 *v1;
    v1 = *(s32 **)((s32)a0 + 0xCC);
    *(s32 *)((s32)v1 + 0xB0) = 2;
    if (func_80180938() != 0) {
        *(s16 *)((s32)a0 + 0x2) = 1;
    }
}
