/* sc02_0037: func_8013E83C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern s32 func_80029178(s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80029178(s32 arg);
extern u16 D_80115110;

void func_8013E83C() {
    extern u16 D_80115110;
    extern u16 D_8011511A;
    extern int func_80029178(int);
    extern void func_8002D4C8(int, int);
    extern void func_80141C0C(int);
    extern unsigned short D_80115118;
    extern unsigned short D_80115128;
    extern unsigned short D_8011512E;
    extern unsigned int D_80115130;
    extern unsigned short D_80115158;
    extern unsigned short D_8011515A;
    extern unsigned short D_8011515C;
    extern unsigned short D_8011515E;
    extern unsigned short D_80115162;
    extern unsigned short D_80115166;
    extern void * D_801C84F0;
    extern void * D_801C84F4;
    extern unsigned char D_80184C24;
    extern unsigned char D_80184C3C;
    extern unsigned char D_80184CB0;
    extern unsigned char D_80184CB8;
    D_80115118 = 0;
    D_80115130 = 0;
    if (D_8011511A >= 4) {
        D_8011511A = D_8011511A - 3;
    }
    D_80115158 = 0x106;
    if ((func_80029178(0x1c) & 0xFF) == 0) {
        D_801C84F0 = &D_80184C24;
        D_801C84F4 = &D_80184CB0;
    } else {
        D_801C84F0 = &D_80184C3C;
        D_801C84F4 = &D_80184CB8;
    }
    D_8011515A = 0x104;
    D_8011515C = 0x104;
    D_8011515E = 0x129;
    D_80115162 = 0x103;
    D_80115166 = 0x105;
    D_80115128 = 0;
    D_8011512E = 0;
    if (D_80115110 == 3) {
        func_8002D4C8(0x46e, 0);
    } else {
        func_80141C0C(0);
    }
}
