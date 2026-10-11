/* sc03_0001: func_8017EFD4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029504(void);
extern void func_8012A568(void (*a0)(void));
void func_8017ED8C(void *a0);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_8017ED8C(void *a0);

void func_8017EFD4(void *a0) {
    s32 v1 = func_80029504();
    s32 v0;
    if (v1 < 0xC8) {
        v0 = ((s32 (*)(void))func_801877C0)();
        v1 = 3;
        if (v0 == v1) goto call_func_8018C24C;
        goto call_func_80184BAC;
    } else if (v1 >= 0x258) {
        if (v1 < 0x384) {
            goto call_func_80184BAC;
        } else {
            v0 = func_80187904();
            v1 = 1;
            if (v0 == v1) goto call_func_8018C24C;
        }
call_func_80184BAC:
        v0 = func_8018766C(0xA, 0x10);
        if (v0 != 0) return;
    } else {
        return;
    }
call_func_8018C24C:
    func_8017ED8C(a0);
}
