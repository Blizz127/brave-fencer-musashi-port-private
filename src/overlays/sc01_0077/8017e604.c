/* sc01_0077: func_8017E604 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80139914(s32 a0);
extern s32 func_8013767C(s32 a0);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_801399F0(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8013767C(s32 a0);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern s32 func_8013767C(s32 a0);
extern s32 func_8013767C(s32 a0);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern s32 func_8013767C(s32 a0);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern s32 func_8013767C(s32 a0);
extern u8 D_801B1848;

void func_8017E604(s32 a0) {
    s32 s0 = a0;
    if (func_801399F0(*(s32 *)(s0 + 0x198)) != 0) {
        func_80139914(*(s32 *)(s0 + 0x198));
        *(s32 *)(s0 + 0x198) = func_8013767C((s32)&D_801B1848);
        *(u8 *)(s0 + 0x214) = *(u8 *)(s0 + 0x214) + 1;
    }
}
