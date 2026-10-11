/* sc03_0001: func_80186DAC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern void func_8012B2CC(s32 a0);
extern s32 func_80178BF8();
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF80186828(void *a0) __asm__("func_80186828");
extern s32 func_80178BF8();
extern void func_80172710(void);
extern void func_8012B2CC(s32 arg);

void func_80186DAC(void *arg0) {
    u16 *p = *(u16 **)((char *)arg0 + 0x20);
    *(s16 *)((char *)arg0 + 0x2) = 4;
    *(s16 *)((char *)p + 0x12) = 0x600;
    func_8012B2CC((s32)arg0);
}
