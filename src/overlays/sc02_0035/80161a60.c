/* SC02.CD member35: func_80161A60 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern u8 D_80078EC0;
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern u8 D_80078EC0;
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
s32 aF8016130C(void *a0, s32 a1)
{
    if ((a1 == 0) || (a1 == 0x8000)) {
        func_801599A4(a0);
        ((void (*)(void *))func_8015BDD0)(a0);
        return 1;
    }
    if ((a1 & 0x4000) != 0) {
        func_801599A4(a0);
        ((void (*)(void *))func_8015BF48)(a0);
        return 1;
    }
    return 0;
}
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_8016191C(void *a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(int a0, int a1);
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
int aF8016191C(int param_1, unsigned int param_2) {
    if (param_2 & 1) {
        func_8014C010(param_1, 1);
        return 1;
    }
    if (param_2 & 0x4000) {
        func_8014C010(param_1, 1);
        return 2;
    }
    if (param_2 & 0x2000) {
        func_8014C010(param_1, 1);
        return 4;
    }
    return 0;
}

s32 func_80161A60(s32 a0) {
    s32 v0;
    if (*(s16*)(a0 + 0x1C8) != 0) {
        v0 = ((D_80078EC0 & 0x7F) ^ 6) == 0;
        return v0;
    }
    return 0;
}
