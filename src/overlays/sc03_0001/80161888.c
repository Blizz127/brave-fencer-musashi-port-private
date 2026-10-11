/* sc03_0001: func_80161888 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern void func_80161D20(int param_1, u32 param_2);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208(void);
extern s32 func_80161208(void);
extern s32 func_80161208(void);
extern void func_801599A4(void *a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_8016130C(void*, s32);
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8016130C(void *a0, s32 a1);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20(int param_1, u32 param_2);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20();
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20(int param_1, u32 param_2);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20();
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
void func_80161D20(int param_1, u32 param_2);

s32 func_80161888(s32 a0, u32 a1)
{
    s32 s0 = a0;
    if (a1 & 1) {
        func_8014C010(s0, 1);
        func_80161D20(s0, *(u16*)(s0 + 0x16E));
        return 1;
    }
    if (a1 & 0x4000) {
        func_8014C010(s0, 1);
        func_80161D20(s0, *(u16*)(s0 + 0x16E));
        return 2;
    }
    if (a1 & 0x2000) {
        func_8014C010(s0, 1);
        func_80161D20(s0, *(u16*)(s0 + 0x16E));
        return 4;
    }
    return 0;
}
