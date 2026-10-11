/* sc03_0001: func_80178B18 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8017435C(void);
extern void func_801746A4(void);
extern void func_80178CBC(s32 a0, s32 a1);
void func_80178CBC(s32 arg0, s32 arg1);

s32 func_80178B18(s32 param_1, s32 param_2)
{
    extern void func_80178BF8(void);
    extern void func_80178CBC(s32 arg0, s32 arg1);
    extern u16 D_80190E48;
    int *p = &(*(int *)&D_80190E48);
    *p = ((int)param_2);
    func_80178BF8();
    func_801746A4();
    func_8017435C();
    ((void (*)(int, void *))func_80178CBC)(((int)param_1), (char *)p - 0xC);
}
