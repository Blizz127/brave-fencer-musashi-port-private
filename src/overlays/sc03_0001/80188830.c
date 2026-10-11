/* sc03_0001: func_80188830 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80188830.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern void func_8012A568(void (*a0)(void));
extern u8 D_80078E78[];
extern void func_80178CBC(s32*, s32);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern s32 func_801877C0(s32 a0);
extern void func_80178CBC(s32 *a0, s32 a1);
extern void func_80178CBC(s32 *, s32);
extern s32 func_80029504(void);
extern s32 func_80029178(s32 arg0);
extern s32 func_801877C0(s32);
extern s32 func_80187904(void);
extern void func_80178CBC(s32*, s32);

void func_80188830(void *a0) {
    extern void *D_801C0DB0[];
    extern s32 D_801C0D80;
    extern s32 D_801C0D98;
    void *s2 = a0;
    register u8 *p __asm__("$17");
    void *s0;
    s32 v0;
    s16 v1;
    v0 = func_80029504();
    v1 = *(s16 *)((s32)s2 + 0x70);
    p = D_80078E78;
    s0 = D_801C0DB0[v1];
    v1 -= 8;
    switch (v1) {
    case 1:
        if (p[0x42] == 0) {
            s0 = &D_801C0D80;
        }
        break;
    case 0:
        if (p[0x42] == 3) {
            s0 = &D_801C0D80;
        }
        break;
    case 4:
        if ((u32)(v0 - 0x12C) < 0x12C) {
            if ((func_80029178(0xFA) & 0xFF) != 0) {
                s0 = &D_801C0D98;
            }
        }
        break;
    case 6:
        if (p[0x42] == 6) {
            s0 = &D_801C0D80;
        }
        if ((u32)(v0 - 0x64) < 0x1F4) {
            s0 = &D_801C0D98;
        }
        if (func_80187904() == 1) {
            s0 = &D_801C0D98;
        }
        break;
    case 5:
        if (p[0x42] == 2) {
            s0 = &D_801C0D80;
        }
        if (((s32 (*)(void))func_801877C0)() == 3) {
            s0 = &D_801C0D98;
        }
        if (func_80187904() == 1) {
            s0 = &D_801C0D98;
        }
        break;
    }
    ((void (*)(s32, s32))func_80178CBC)((s32)s2, (s32)s0);
}
