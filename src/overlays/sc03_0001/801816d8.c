/* sc03_0001: func_801816D8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern s32 func_80029504(void);
extern u8 D_80078EBA;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_80029504(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32 a0);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 a0, s32 a1);
extern u8 D_80078EBA;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);

s32 func_801816D8(void) {
    u8 d = D_80078EBA;
    s32 v1;
    s32 v0;
    if (d == 6) {
        if (func_8018766C(0, 0xC) == 0) {
            return 0;
        }
    } else if (d == 0) {
        if (func_8018766C(0, 0xC) != 0) {
            return 0;
        }
    }
    v1 = func_80029504();
    if (v1 < 0xC8) {
        v1 = ((s32 (*)(void))func_801877C0)();
        if (v1 < 0) {
            return v1;
        }
        if (v1 < 3) {
            goto common;
        }
        v0 = v1 < 5;
        if (!v0) {
            goto ret0;
        }
        v0 = 0;
ret0:
        return v0;
    } else {
        if (v1 < 0x258) {
            return 0;
        }
    }
    if (v1 < 0x384) {
common:
        return func_8018766C(2, 0x12) == 0;
    }
    if (func_8018766C(2, 0x12) == 0) {
        return func_80187904() != 1;
    }
    return 0;
}
