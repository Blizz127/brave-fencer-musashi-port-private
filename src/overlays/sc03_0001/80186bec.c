/* sc03_0001: func_80186BEC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32, s32);
extern void func_8001C214(s32, s32);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern void func_8001C214(s32 a0, s32 a1);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF80186828(void *a0) __asm__("func_80186828");
extern void func_8012A828(s32, s32);
extern void func_8012A828(s32, s32);
extern M2C_UNK D_801C3CE8;
extern u8 D_801CDAD8[];
extern void func_8001C214(s32, s32);
extern void func_8012A828(s32, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);

void func_80186BEC(void *a0) {
        s32 v0 = ((s32 (*)(void *))func_8012C1B8)(a0);
        *(int *)((char *)a0 + 0x20) = v0;
        if (v0 == 0) {
            func_8012CAE4(a0);
        } else {
            ((void (*)(s32, u8 *))func_8001C214)(v0, D_801CDAD8);
            ((void (*)(void *, u8 *))func_8012A828)(a0, ((u8 *)&D_801C3CE8));
            *(short *)((char *)a0 + 0x2) = 1;
        }
    }
