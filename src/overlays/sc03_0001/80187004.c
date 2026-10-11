/* sc03_0001: func_80187004 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80029124(s32, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80029124(s32 a0, s32 a1);
extern void func_800D0F4C(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern s32 func_8012E57C(s32 a0, s32 a1);
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
s32 func_80186D18(void);
extern s32 func_80186D18(void);
extern s32 func_80178BF8();
extern void func_80172710(void);
s32 aF8018CB18(void *a0) __asm__("func_8018CB18");
extern void func_80029124(s32, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_800D0F4C(s32 a0);
extern s32 func_8012E57C(s32 a0, s32 a1);

void func_80187004(void *a0)
{
    s32 result;
    *(u16 *)((s32)a0 + 0x34) = *(u16 *)((s32)a0 + 0x34) + 1;
    func_8002D4C8(0x7A0, 0);
    func_80029124(0xF6, 1);
    func_800D0F4C(0x59);
    result = func_8012E57C(0x1F2, 1);
    if (result) {
        *(u16 *)(result + 0x34) = *(u16 *)(result + 0x34) + 1;
    }
}
