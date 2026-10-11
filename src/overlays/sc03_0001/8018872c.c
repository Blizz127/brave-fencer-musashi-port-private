/* sc03_0001: func_8018872C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s16 D_800B9A08;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s16 D_800B9A08;
extern s32 func_801887D0(void *a0);
extern s32 func_80188D68(void *a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
s32 func_801887D0(void *a0);

void *func_8018872C(void *a0) {
    if (D_800B9A08 == 0x3069) {
        return 0;
    }
    if (*(u16 *)((s32)a0 + 0x2) != 2) {
        return 0;
    }
    if (*(u16 *)((s32)a0 + 0x34) != 0) {
        return 0;
    }
    if (*(s16 *)((s32)a0 + 0x10A) != 0) {
        return 0;
    }
    if (func_801887D0(a0) == 0) {
        return 0;
    }
    if (func_80188D68(a0) != 0) {
        return 0;
    }
    *(s16 *)((s32)a0 + 0x34) = 1;
    func_80178BF8();
    return (void *)func_80172710;
}
