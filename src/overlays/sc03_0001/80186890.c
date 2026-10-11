/* sc03_0001: func_80186890 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 func_80178BF8();
extern void func_8012A828(s32, s32);
extern void func_8012E8E0(s32, s32);
extern void func_80187750(s32);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80187750(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF80186828(void *a0) __asm__("func_80186828");
extern void func_8012E8E0(s32, s32);
extern void func_80187750(s32);
extern void func_8012A828(s32, s32);
extern s32 D_80192A64;
extern s32 D_801C3C90;

void func_80186890(s32 a0) {
    *(s16 *)(a0 + 2) = 4;
    func_8012E8E0(a0, (s32)&D_80192A64);
    func_80187750(a0);
    func_8012A828(a0, (s32)&D_801C3C90);
}
