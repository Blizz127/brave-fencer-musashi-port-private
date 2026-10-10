/* sc03_0098: func_8017CC80 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern int func_80178970(void);
extern void func_80178D18(void);
void func_8017BEBC(s32 param_1, s32 param_2);
extern s32 func_8005C49C(void);
extern void func_8017BEBC(s32 a0, s32 a1);
extern void func_8017BEBC(s32 a0, s32 a1);
extern void func_8017BEBC(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern int func_80178970(void);
extern void func_80178D18(void);

void func_8017CC80(s32 a0) {
    extern int func_80178970(void);
    extern void func_80178D18(void);
    s32 rand_val = func_8005C49C();
    func_8017BEBC(a0, rand_val & 0xF);
    if (((s32 (*)(s32))func_80178970)(a0) == 0) {
        return;
    }
    ((void (*)(s32))func_80178D18)(a0);
    *(s16 *)(a0 + 0x2) = 1;
}
