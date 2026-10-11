/* sc03_0001: func_801815A0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32*, s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018727C(void *a0, void *a1);
extern s32 func_801788B8(s32 a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern short D_80191B3C;
extern void func_80187778(s32 *a0, s32 a1);
extern short D_80191B3C;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern short D_80191B3C;
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern s32 func_8018727C(void *a0, void *a1);
extern s32 func_8018766C(s32 a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_801788B8(s32 a0, s32 a1);
extern short D_80191B3C;
extern s32 D_80191B44;
extern void func_8018166C(void *);

void func_801815A0(void *arg0) {
    void *s0 = arg0;
    s32 v1;
    s32 v0;
    void *ptr;
    if (func_8018727C(arg0, &D_80191B44) == 0) {
        return;
    }
    if (func_8018766C(6, 0x12) != 0) {
        v1 = 1;
    } else {
        v1 = (func_8018766C(0x12, 0x15) != 0) << 1;
    }
    switch (v1) {
    case 0:
        v0 = 1;
        break;
    case 1:
        v0 = 2;
        break;
    case 2:
        v0 = 3;
        break;
    default:
        goto tail;
    }
    *(short *)((char *)s0 + 2) = v0;
    func_80187778((s32 *)s0, (s32)&D_80191B3C);
tail:
    ptr = *(void **)((char *)s0 + 0x68);
    *(short *)((char *)ptr + 0xC) = 0x7FFF;
    *(s32 *)((char *)s0 + 0xD4) = func_801788B8((s32)s0, (s32)func_8018166C);
}
