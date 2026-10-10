/* sc01_0077: func_8013E83C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern u16 D_80115110;
extern u16 D_8011511A;
extern u16 D_80115110;
void func_80141C0C(s32 param_1);

void func_8013E83C() {
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
    extern void * D_801D95C8;
    extern void * D_801D95CC;
    extern unsigned char D_80187B34;
    extern unsigned char D_80187B4C;
    extern unsigned char D_80187BC0;
    extern unsigned char D_80187BC8;
    D_80115118 = 0;
    D_80115130 = 0;
    if (D_8011511A >= 4) {
        D_8011511A = D_8011511A - 3;
    }
    D_80115158 = 0x106;
    if ((func_80029178(0x1c) & 0xFF) == 0) {
        D_801D95C8 = &D_80187B34;
        D_801D95CC = &D_80187BC0;
    } else {
        D_801D95C8 = &D_80187B4C;
        D_801D95CC = &D_80187BC8;
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
