/* sc03_0001: func_801723C4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8014A1B0(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_80147078(s32 *, s16);
extern void func_8012A568(void (*a0)(void));
extern void func_801599A4(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8014A1B0(s32 a0, s32 a1);

void func_801723C4(s32 param_1, s32 param_2)
{
    ((void (*)(void))func_801599A4)();
    ((void (*)(int, int))func_80147078)(param_1, 0xd);
    *(int *)(param_1 + 0x178) = param_2;
    func_8014A1B0(param_1, param_2);
}
