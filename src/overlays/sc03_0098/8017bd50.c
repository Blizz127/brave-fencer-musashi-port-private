/* sc03_0098: func_8017BD50 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s16 D_801C5840;
void func_8017B0E4(int param_1, int param_2);
extern s16 D_801C5424;
extern s16 D_801C5840;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s16 D_801C5424;
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
extern s16 D_801C5424;
extern short D_801C54AC;
extern short D_801C54AE;
extern short D_801C54B0;
extern void func_8017B0E4(int, int);
extern s16 D_801C5424;
extern s16 D_801C5840;
extern s16 D_801C5424;
extern s16 D_801C5840;
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);
extern s16 D_801C5424;
extern void (*D_801C5468)(void);
extern short D_801C54AC;
extern short D_801C54AE;
extern short D_801C54B0;
extern s16 D_801C5840;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;

void func_8017BD50(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801C5424 = D_801C5424 + 1;
    if (D_801C5424 >= 0x19) {
        if (D_801C5468 != 0) {
            (*D_801C5468)();
        } else {
            D_80114F30 = D_80114F30 + D_801C54AC;
            D_80114F34 = D_80114F34 + D_801C54AE;
            D_80114F38 = D_80114F38 + D_801C54B0;
            D_80114F24 = D_80114F24 + D_801C54AC;
            D_80114F28 = D_80114F28 + D_801C54AE;
            D_80114F2C = D_80114F2C + D_801C54B0;
            func_8012A4BC();
        }
        D_801C5840 = 0;
    }
}
