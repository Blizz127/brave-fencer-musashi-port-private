/* SC02.CD member35: func_80169FE0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_80147324(s32 arg0);
extern s32 func_800CF8B4();
extern void func_801599A4(void *a0);
extern void func_80162CCC(void);
extern void func_80016714(void *a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BDD0(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern s32 func_80161CD0(s32 a0, s32 a1);
extern s32 func_800CF8B4(void);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_800CF8B4(void);
extern s32 func_80161208();
extern void func_80147324(s32 a0);
extern s32 func_80161208(void);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_80161208(void);
extern s32 func_80161208(void);
extern void func_80147324(s32 a0);
extern void func_801599A4(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 arg0);
extern s32 func_800CF8B4();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
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
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
extern void func_80147324();
extern void func_80147324(s32 arg0);
extern int func_800CF8B4();
extern void func_80147324(int arg0);
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
void aF80161CD0(int param_1, unsigned int param_2)
{
    extern unsigned short D_80186FB8;
    if (param_2 < 8) {
        if (func_800CF8B4() != 0) {
            func_80147324((&D_80186FB8)[param_2]);
        }
    }
}
extern void func_80147324(s32 arg0);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
void aF80162CCC(u8 *a0)
{
    u8 *s0 = a0;
    u16 *p = *(u16 **)(s0 + 0x20);
    if (p != 0) {
        s32 a1;
        if (*p == 1) {
            a1 = 0x84;
        } else {
            a1 = 0x38;
        }
        func_80016714(p, a1);
    }
    func_80016714(s0, 0x68);
}
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern void func_80162CCC();
extern void func_80162CCC();
extern void func_80162CCC();
extern s32 func_80161208();
extern void func_801599A4(void *a0);
extern void func_80016714(void *a0, s32 a1);
extern void func_80146C3C();
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80147324(s32 arg0);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();

void func_80169FE0(s32 a0) {
    if (func_80128ED8((void *)*(s32 *)(a0 + 0x20), (void *)(a0 + 0x24)) != 0) {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
