/* SC02.CD member35: func_80183B20 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012B178(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012CBF4(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B200(void *a0);
extern void func_80183E68(s32 *a0, s32 a1, s32 a2);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012CBF4(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B200(void *a0);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012CBF4(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_80183E68(s32 *a0, s32 a1, s32 a2);
extern void func_8012B200(void *a0);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_80183E68(s32 *a0, s32 a1, s32 a2);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012CBF4(s32 a0);
extern void func_8012B200(void *a0);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80183E3C(s32 a0);
extern s32 func_8005C49C(void);
extern u8 D_801B974C[];
s32 func_80183E3C(s32 arg0);
void func_80183E68(s32 *a0, s32 a1, s32 a2);

void func_80183B20(s32 a0) {
    s32 sp10[2];
    s32 t;
    s32 u;
    switch (*(u16 *)(a0 + 0x34)) {
    case 0:
        if (((s32 (*)(s32))func_8012CBF4)(a0)) {
            *(s32 *)(a0 + 0x1C) = 0x1E;
            *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0;
            *(s16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
        } else if (*(s16 *)(a0 + 0x100) < *(s16 *)(a0 + 0xA)) {
            *(s16 *)(a0 + 0xA) = *(s16 *)(a0 + 0x100);
            *(s32 *)(a0 + 0x1C) = 0x1E;
            *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0;
            *(s16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
        }
        break;
    case 1:
        t = func_8012B8E4(a0, 6);
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) =
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + t;
        if (func_8012BEE8(a0)) {
            if (func_8005C49C() & 1) {
                *(s16 *)(a0 + 0x2) = 1;
            } else {
                *(s16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
                func_8012B200((void *)a0);
                *(s32 *)(a0 + 0x1C) = 0x20;
                func_8002D4C8(0x6FF, 0);
            }
        }
        break;
    case 2:
        func_80183E68(sp10, a0, (s32)D_801B974C);
        u = sp10[0];
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = u;
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) = u >> 16;
        func_8012B178(a0, *(s32 *)(a0 + 0xE4) + 0xFFF80000);
        func_8012CBF4(a0);
        if (func_80183E3C(a0) == 1) {
            *(s16 *)(a0 + 0x2) = 1;
        } else if (func_8012BEE8(a0)) {
            *(s16 *)(a0 + 0x2) = 1;
        }
        break;
    default:
        *(s16 *)(a0 + 0x2) = 1;
        break;
    }
}
