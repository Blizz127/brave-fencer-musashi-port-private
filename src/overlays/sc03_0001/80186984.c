/* sc03_0001: func_80186984 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern s32 func_80128C98(s32 arg);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF80186828(void *a0) __asm__("func_80186828");

void func_80186984(void *a0) {
    extern s32 func_80128C98(s32 arg);
    extern void func_801EF558(void *a0);
    *(u16 *)((char *)a0 + 2) = 5;
    if (func_80128C98(2)) {
        ((void (*)(void *))func_801EF558)(a0);
    }
}
