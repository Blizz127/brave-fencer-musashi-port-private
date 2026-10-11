/* sc03_0001: func_80180C68 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801877C0(s32);
extern void func_80178CBC(s32*, s32);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32);
extern void func_80178CBC(s32 *a0, s32 a1);
extern s32 D_80191A0C;
extern s32 D_80191A74;

void func_80180C68(s32 *param_1)
{
    s32 v0;
    *(short *)((char *)param_1 + 0x2) = 5;
    v0 = ((s32 (*)(void))func_801877C0)();
    if (v0 != 1) {
        func_80178CBC(param_1, (s32)&D_80191A0C);
        *(short *)((char *)param_1 + 0x34) = 0;
    } else {
        func_80178CBC(param_1, (s32)&D_80191A74);
        *(short *)((char *)param_1 + 0x34) = 1;
    }
}
