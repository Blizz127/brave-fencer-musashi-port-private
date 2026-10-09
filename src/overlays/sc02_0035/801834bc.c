/* SC02.CD member35: func_801834BC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
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
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8005C49C(void);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8005C49C(void);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_80183E68(s32 *a0, s32 a1, s32 a2);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012CBF4(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_80183F14(void);
extern s32 func_8005C49C(void);
void func_80183E68(s32 *a0, s32 a1, s32 a2);
s32 func_80183F14(void);

void func_801834BC(s32 a0) {
    s32 sp10[2];
    s32 t;
    s32 r;
    func_80183E68(sp10, a0, a0 + 0x102);
    t = sp10[0];
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = t;
    r = func_8012B608(*(s16 *)(*(s32 *)(a0 + 0x20) + 0x12), t >> 16,
                      *(s16 *)(a0 + 0xFE));
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) =
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + r;
    func_8012B178(a0, *(s32 *)(a0 + 0xE4));
    func_8012CBF4(a0);
    if ((*(u16 *)(a0 + 0x70) & 2) == 0) {
        if (func_8012BEE8(a0)) {
            if (*(s32 *)(a0 + 0xE0) == 0) {
                if (((s32 (*)(s32))func_80183F14)(a0)) {
                    if (*(u16 *)(a0 + 0x70) & 1) {
                        *(s32 *)(a0 + 0x1C) = func_8005C49C() % 0x708 + 0xE10;
                    } else {
                        *(s32 *)(a0 + 0x1C) = func_8005C49C() % 0x3C + 0x78;
                    }
                } else {
                    *(s16 *)(a0 + 0x2) = 5;
                }
            } else {
                *(s16 *)(a0 + 0x2) = 1;
            }
        }
    }
}
