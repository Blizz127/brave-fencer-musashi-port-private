/* sc01_0077: func_8017BD50 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s16 D_801DAAB8;
void func_8017B0E4(int param_1, int param_2);
extern s16 D_801DA71C;
extern s16 D_801DAAB8;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s16 D_801DA71C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s16 D_801DA71C;
extern short D_801DA7A4;
extern short D_801DA7A6;
extern short D_801DA7A8;
extern void func_8017B0E4(int, int);
extern s16 D_801DA71C;
extern s16 D_801DAAB8;
extern s16 D_801DA71C;
extern s16 D_801DAAB8;
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);
extern s16 D_801DA71C;
extern void (*D_801DA760)(void);
extern short D_801DA7A4;
extern short D_801DA7A6;
extern short D_801DA7A8;
extern s16 D_801DAAB8;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;

void func_8017BD50(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801DA71C = D_801DA71C + 1;
    if (D_801DA71C >= 0x19) {
        if (D_801DA760 != 0) {
            (*D_801DA760)();
        } else {
            D_80114F30 = D_80114F30 + D_801DA7A4;
            D_80114F34 = D_80114F34 + D_801DA7A6;
            D_80114F38 = D_80114F38 + D_801DA7A8;
            D_80114F24 = D_80114F24 + D_801DA7A4;
            D_80114F28 = D_80114F28 + D_801DA7A6;
            D_80114F2C = D_80114F2C + D_801DA7A8;
            func_8012A4BC();
        }
        D_801DAAB8 = 0;
    }
}
