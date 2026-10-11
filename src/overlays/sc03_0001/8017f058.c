/* sc03_0001: func_8017F058 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern void func_8012A568(void (*a0)(void));
extern void func_80187778(s32 *a0, s32 a1);
extern short D_801913D4;
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);

void func_8017F058(void *a0) {
    extern short D_801913D4;
    void *s0 = a0;
    s32 v1 = func_80029504();
    s32 v0;
    if (v1 < 0xC8) {
        v0 = ((s32 (*)(void))func_801877C0)();
        v1 = 3;
        if (v0 == v1) {
            return;
        }
        v0 = func_8018766C(0xA, 0x10);
        if (v0 == 0) {
            return;
        }
        v0 = 1;
    } else if (v1 < 0x258) {
        v0 = 1;
    } else if (v1 < 0x384) {
        v0 = func_8018766C(0xA, 0x10);
        if (v0 == 0) {
            return;
        }
        v0 = 1;
    } else {
        v0 = func_80187904();
        v1 = 1;
        if (v0 == v1) {
            return;
        }
        v0 = func_8018766C(0xA, 0x10);
        if (v0 == 0) {
            return;
        }
        v0 = 1;
    }
    *(s16 *)((char *)s0 + 0x2) = 0x1;
    ((void (*)(s32, s32))func_80187778)((s32)s0, (s32)&D_801913D4);
}
