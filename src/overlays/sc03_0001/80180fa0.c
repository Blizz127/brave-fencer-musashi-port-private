/* sc03_0001: func_80180FA0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
void func_80180B1C(s32 a0);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern void func_80188A14(void *a0, s32 a1, s32 a2);
extern s32 func_80187A64(s32 a0);
extern void func_80188A14(void *a0, s32 a1, s32 a2);
extern s32 func_801886A0(s32 arg0);
extern s32 func_80187A64(s32 a0);

void func_80180FA0(void *arg0) {
    func_80188A14(arg0, 0xC, 1);
    if (func_801886A0(0xC)) {
        if (func_80187A64((s32)arg0)) {
            func_80180B1C((s32)arg0);
        }
    }
}
