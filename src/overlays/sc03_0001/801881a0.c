/* sc03_0001: func_801881A0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80029504(void);
s32 aF801877C0(void) __asm__("func_801877C0");
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
s32 func_80187C2C(s32 a0);
extern void func_801883C4(s32 a0);
extern s32 func_80187C2C(s32 a0);
extern void func_801883C4(s32 a0);
extern void func_8012E688(s32 param_1, u16 param_2, u16 param_3);
extern s32 func_801889AC(void);
void func_801883C4(s32 a0);

void func_801881A0(s32 a0) {
    s32 s0;
    u16 v0;
    u16 v1;
    if (func_80187C2C(a0) == 2) {
        func_801883C4(a0);
    }
    s0 = a0;
    v0 = *(u16 *)(s0 + 0x84);
    v0 = v0 + 1;
    *(u16 *)(s0 + 0x84) = v0;
    if ((s16)v0 == 8) {
        func_8012E688(s0, 0x514, 0);
    }
    v0 = *(u16 *)(s0 + 0x100);
    v1 = *(u16 *)(s0 + 0x102);
    v0 = v0 + v1;
    *(u16 *)(s0 + 0x100) = v0;
    if ((s16)v0 >= 0x50) {
        *(u16 *)(s0 + 0x100) = 0x50;
    }
    v0 = *(u16 *)(s0 + 0xFE);
    v1 = *(u16 *)(s0 + 0x100);
    v0 = v0 + v1;
    *(u16 *)(s0 + 0xFE) = v0;
    if ((s16)v0 >= 0x600) {
        func_801883C4(s0);
    }
    ((void (*)(s32))func_801889AC)(s0);
}
