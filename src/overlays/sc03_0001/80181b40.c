/* sc03_0001: func_80181B40 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32*, s32);
extern s32 func_8018727C(void *a0, void *a1);
extern s32 func_801788B8(s32 a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern s32 func_8018727C(void *a0, void *a1);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_801788B8(s32 a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern short D_80191C28;
s32 func_80181948(s32 a0);
extern s32 func_80181948(s32 a0);
s32 func_80181BC0(void *a0);

void func_80181B40(void *arg0) {
    extern s32 func_8018727C(void *a0, void *a1);
    extern s32 func_80181948(s32 a0);
    extern void func_80187778(s32 *a0, s32 a1);
    extern s32 func_801788B8(s32 a0, s32 a1);
    extern s32 func_80181BC0(void *a0);
    extern short D_80191C28;
    extern s32 D_80191C30[];
    void *v1;
    if (func_8018727C(arg0, &D_80191C30) == 0) {
        return;
    }
    if (((int (*)(void))func_80181948)() != 0) {
        *(s16 *)((char *)arg0 + 2) = 2;
    } else {
        *(s16 *)((char *)arg0 + 2) = 1;
    }
    func_80187778((s32 *)arg0, (s32)&D_80191C28);
    v1 = *(void **)((char *)arg0 + 0x68);
    *(s16 *)((char *)v1 + 0xC) = 0x7FFF;
    *(s32 *)((char *)arg0 + 0xD4) = func_801788B8((s32)arg0, (s32)func_80181BC0);
}
