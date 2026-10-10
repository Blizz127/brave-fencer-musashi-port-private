/* sc01_0077: func_80162B1C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80161CD0(s32 a0, s32 a1);
extern s32 D_8011F9D0;
extern void func_80147324(s32 arg0);
extern s32 func_800CF8B4();
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BDD0(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_8015BF48(s32 *a0);
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern void func_801599A4(void *a0);
extern s32 func_80161208();
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
extern s32 func_80161208();
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
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
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
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
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
extern void func_80147324();
extern void func_80147324(s32 arg0);
extern int func_800CF8B4();
extern void func_80147324(int arg0);
extern unsigned short D_80189604;
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
extern void func_80147324(s32 arg0);
extern s32 D_8011F9D0;
extern void func_80162CC4(void);
extern s32 D_80126D40;
extern s32 D_8011F9D0;
void func_80162CC4(void);

void func_80162B1C(void) {
    s32 s3 = *(s32 *)&D_80126D40;
    s32 s2 = 0;
    s32 s1 = 0;
    s32 s0;
    s32 a0;
    s32 p;
    s32 fp;
    void (*f)(s32);
    do {
        s0 = s1 + (s32)&D_8011F9D0;
        *(s16 *)(s0 + 0x44) = *(u16 *)(s0 + 0x6);
        *(s16 *)(s0 + 0x46) = *(u16 *)(s0 + 0xA);
        *(s16 *)(s0 + 0x48) = *(u16 *)(s0 + 0xE);
        if (*(u16 *)(s0 + 0x0) != 0) {
            fp = *(s32 *)((*(u16 *)(s0 + 0x0) << 2) + s3 - 4);
            if (fp != 0) {
                f = (void (*)(s32))fp;
                f(s0);
            } else {
                ((void (*)(s32))func_80162CC4)(s0);
            }
            a0 = *(s32 *)(s0 + 0x20);
            if (a0 != 0) {
                if (*(u16 *)a0 == 1) {
                    s32 b0 = *(u16 *)(s0 + 0x6);
                    *(s16 *)(a0 + 0x8) = b0;
                    *(s32 *)(a0 + 0x48) = (s16)b0;
                    b0 = *(u16 *)(s0 + 0xA);
                    *(s16 *)(a0 + 0xA) = b0;
                    *(s32 *)(a0 + 0x4C) = (s16)b0;
                    {
                        s32 m = *(u16 *)(a0 + 0x2C) | 1;
                        s32 c0 = *(u16 *)(s0 + 0xE);
                        *(s16 *)(a0 + 0xC) = c0;
                        *(s16 *)(a0 + 0x2C) = m;
                        *(s32 *)(a0 + 0x50) = (s16)c0;
                    }
                } else if ((p = *(s32 *)(a0 + 0x34)) != 0) {
                    s32 b0 = *(u16 *)(s0 + 0x6);
                    *(s16 *)(a0 + 0x8) = b0;
                    *(s32 *)(p + 0x14) = (s16)b0;
                    b0 = *(u16 *)(s0 + 0xA);
                    *(s16 *)(a0 + 0xA) = b0;
                    *(s32 *)(*(s32 *)(a0 + 0x34) + 0x18) = (s16)b0;
                    b0 = *(u16 *)(s0 + 0xE);
                    *(s16 *)(a0 + 0xC) = b0;
                    *(s32 *)(*(s32 *)(a0 + 0x34) + 0x1C) = (s16)b0;
                } else {
                    *(s16 *)(a0 + 0x8) = *(u16 *)(s0 + 0x6);
                    *(s16 *)(a0 + 0xA) = *(u16 *)(s0 + 0xA);
                    *(s16 *)(a0 + 0xC) = *(u16 *)(s0 + 0xE);
                }
            }
        }
        s2 += 1;
        s1 += 0x68;
    } while (s2 < 0x14);
}
