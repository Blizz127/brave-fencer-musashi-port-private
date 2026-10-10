/* sc03_0098: func_8016C188 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_801465C0(void);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80149350(s32 arg0);
extern void func_800233CC(void *, unsigned short);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_8001CD9C(int, void *);
extern void func_800233CC(void *, unsigned short);
extern void func_80146C3C();
extern void func_80015954(s32 a0, s32 a1);
extern void func_80146C3C();
extern void func_80149350(s32 arg0);
extern void func_80015954(s32 a0, s32 a1);
extern void func_801465C0(void);
extern void func_80149350(s32 arg0);
s32 func_8016C374(s32 a0, s32 a1, s32 a2, s32 a3);

void func_8016C188(s32 param)
{
    register s32 s1 __asm__("$17");
    s32 s2;
    u8 *s0;
    u16 buf[3];
    s16 *pBCC;
    s16 *pBD4;
    s32 t34;
    extern void func_80015954(s32, s32);
    extern s32 func_8016C374(s32, s32, s32, s32);
    extern void func_80146C3C(void);
    extern void func_8001CD9C(s32, void *);
    extern void func_800233CC(void *, unsigned short);
    extern u8 D_801C488C[];
    extern s16 D_801C48D4;
    extern s16 D_801C48D6;
    extern s16 D_801C48D8;
    extern s16 D_801C48DC;
    extern s16 D_801C48DE;
    extern s16 D_801C48E0;
    s1 = param;
    s2 = ((s32 (*)(void))func_801465C0)();
    *(s32 *)(s1 + 0x20) = s2;
    if (s2 != 0) {
        *(u16 *)(s1 + 0x12) = *(u16 *)(s1 + 0x6);
        *(u16 *)(s1 + 0x16) = *(u16 *)(s1 + 0xA);
        *(u16 *)(s1 + 0x1A) = *(u16 *)(s1 + 0xE);
        t34 = *(s32 *)(s1 + 0x34);
        buf[0] = *(u16 *)(s1 + 0x12);
        buf[1] = *(u16 *)(s1 + 0x16);
        buf[2] = *(u16 *)(s1 + 0x1A);
        ((void (*)(s32, void *, void *))func_80149350)(t34, buf, buf);
        ((void (*)(void *, s32))func_80015954)(buf, s1 + 4);
        s0 = D_801C488C;
        ((void (*)(s32, void *))func_8001CD9C)(s2, s0);
        *(s16 *)(s2 + 0x1E) = 0xCCC;
        *(s32 *)(s2 + 4) = *(s32 *)(s2 + 4) | 0x50000000;
        ((void (*)(void *, s32))func_800233CC)(s0, 0x80);
        *(s16 *)(s2 + 0x1A) = 0;
        *(s16 *)(s2 + 0x18) = 0;
        *(s16 *)(s1 + 0x10) = 0;
        pBCC = &D_801C48D4;
        pBD4 = &D_801C48DC;
        *pBCC = 0x20;
        D_801C48D6 = 0x20;
        D_801C48D8 = 0;
        *pBD4 = 0xC0;
        D_801C48DE = 0xC0;
        D_801C48E0 = 0;
        ((s32 (*)(s32, void *, void *, void *))func_8016C374)(s1, pBCC, pBD4, s0);
        *(u16 *)(s1 + 2) = *(u16 *)(s1 + 2) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)(s1);
    }
}
