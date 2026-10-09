/* SC02.CD member35: func_801837C0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B178(s32 a0, s32 a1);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012CBF4(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8005C49C(void);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8012B77C(s32 out, s32 from, s32 to);
extern s32 func_8005C49C(void);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012CBF4(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern s32 func_8012B77C(s32 out, s32 from, s32 to);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012CBF4(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern s32 func_8005C49C(void);

void func_801837C0(s32 a0) {
    extern u16 D_80126B62;
    s32 sp10[6];
    u8 sp28[8];
    s16 q;
    s32 t;
    s32 r;
    *(s16 *)((s32)sp10 + 0x2) = *(u16 *)(a0 + 0x102);
    *(s16 *)((s32)sp10 + 0xA) = *(u16 *)(a0 + 0x106);
    q = *(u16 *)(a0 + 0x104);
    *(s16 *)((s32)sp10 + 0x6) = q;
    if ((*(u16 *)(a0 + 0x70) & 0x20) == 0) {
        *(s16 *)((s32)sp10 + 0x6) = q + D_80126B62;
    } else {
        *(s16 *)((s32)sp10 + 0x6) = q + *(u16 *)(a0 + 0x8A);
    }
    func_8012B77C((s32)sp28, a0 + 4, (s32)sp10);
    t = *(s32 *)sp28;
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = t;
    r = func_8012B608(*(s16 *)(*(s32 *)(a0 + 0x20) + 0x12), t >> 16,
                      *(s16 *)(a0 + 0xFE));
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) =
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + r;
    func_8012B178(a0, *(s32 *)(a0 + 0xE4));
    func_8012CBF4(a0);
    if (func_8012BEE8(a0)) {
        s32 base;
        s32 off;
        s32 val;
        *(s32 *)(a0 + 0x1C) = func_8005C49C() % 128 + 0x80;
        *(s16 *)(a0 + 0xFE) = func_8005C49C() % 32 + 10;
        func_8012B0B4((unsigned int *)sp28, func_8005C49C() % 0x1000,
                      func_8005C49C() % *(s32 *)(a0 + 0xDC));
        t = *(s32 *)sp28;
        *(s16 *)(a0 + 0x102) = *(u16 *)(a0 + 0x88) + t;
        *(s16 *)(a0 + 0x106) = *(u16 *)(a0 + 0x8C) + (t >> 16);
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
    }
}
