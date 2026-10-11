/* sc03_0001: func_80180634 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern u8 D_80078EBA;
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;

s32 func_80180634(void) {
    s32 v0;
    v0 = ((s32 (*)(void))func_801877C0)();
    if (v0 == 3) {
        return 1;
    }
    v0 = func_80187904();
    if (v0 == 1) {
        return 1;
    }
    if (D_80078EBA != 2) {
        return func_8018766C(0xC, 0x14) == 0;
    }
    return 1;
}
