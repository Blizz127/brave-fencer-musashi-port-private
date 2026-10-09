/* SC02.CD member35: func_8018362C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B200(void *a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B200(void *a0);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);

void func_8018362C(s32 a0) {
    u8 auStack_18[8];
    s32 tmp;
    s32 base;
    s32 off;
    s32 val;
    func_8012B200((void *)a0);
    *(s32 *)(a0 + 0x1C) = func_8005C49C() % 128 + 0x80;
    *(s16 *)(a0 + 0xFE) = func_8005C49C() % 32 + 10;
    func_8012B0B4((unsigned int *)auStack_18, func_8005C49C() % 0x1000,
                  func_8005C49C() % *(s32 *)(a0 + 0xDC));
    tmp = *(s32 *)auStack_18;
    *(s16 *)(a0 + 0x102) = *(u16 *)(a0 + 0x88) + tmp;
    *(s16 *)(a0 + 0x106) = *(u16 *)(a0 + 0x8C) + (tmp >> 16);
    if (*(u16 *)(a0 + 0x70) & 0x20) {
        off = func_8005C49C() % 256;
        base = *(s16 *)(a0 + 0xFC);
        if (func_8005C49C() & 1) {
            val = base + off;
        } else {
            val = base - off;
        }
        *(s16 *)(a0 + 0x104) = val;
    } else {
        *(s16 *)(a0 + 0x104) = *(u16 *)(a0 + 0xFC) - func_8005C49C() % 256;
    }
    *(s16 *)(a0 + 0x2) = 4;
}
