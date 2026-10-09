/* SC02.CD member35: func_8017BD50 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s16 D_801BE9D0;
void func_8017B0E4(int param_1, int param_2);
extern s16 D_801BE834;
extern s16 D_801BE9D0;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s16 D_801BE834;
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
extern s16 D_801BE834;
extern short D_801BE8BC;
extern short D_801BE8BE;
extern short D_801BE8C0;
extern void func_8017B0E4(int, int);
extern s16 D_801BE834;
extern s16 D_801BE9D0;
extern s16 D_801BE9D0;
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);
extern s16 D_801BE834;
extern void (*D_801BE878)(void);
extern short D_801BE8BC;
extern short D_801BE8BE;
extern short D_801BE8C0;
extern s16 D_801BE9D0;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;

void func_8017BD50(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801BE834 = D_801BE834 + 1;
    if (D_801BE834 >= 0x19) {
        if (D_801BE878 != 0) {
            (*D_801BE878)();
        } else {
            D_80114F30 = D_80114F30 + D_801BE8BC;
            D_80114F34 = D_80114F34 + D_801BE8BE;
            D_80114F38 = D_80114F38 + D_801BE8C0;
            D_80114F24 = D_80114F24 + D_801BE8BC;
            D_80114F28 = D_80114F28 + D_801BE8BE;
            D_80114F2C = D_80114F2C + D_801BE8C0;
            func_8012A4BC();
        }
        D_801BE9D0 = 0;
    }
}
