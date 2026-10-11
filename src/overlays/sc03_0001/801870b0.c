/* sc03_0001: func_801870B0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern int func_800D0F8C(int a0);
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80178CBC(s32*, s32);
extern void func_80178CBC(s32 *a0, s32 a1);
extern void func_80178CBC(s32 *, s32);
extern void func_80186D7C(void *arg0);
extern int func_80178970(void);
extern void func_80178D18(void);
extern s32 func_800D0F8C(s32);
extern void func_80178CBC();
extern void func_80186D7C();
extern u8 D_801C057C[];
extern u8 D_801C0594[];

void func_801870B0(void *a0)
{
    s32 *p;
    s32 t;
    switch (*(u16 *)((char *)a0 + 0x34)) {
    case 0:
        break;
    case 1:
        if (func_800D0F8C(0x59) == 0) {
            func_80178CBC(a0, D_801C057C);
            *(u16 *)((char *)a0 + 0x34) = 2;
        } else {
            func_80178CBC(a0, D_801C0594);
            *(u16 *)((char *)a0 + 0x34) = 3;
        }
        break;
    case 2:
        if (((s32 (*)(s32))func_80178970)(a0) != 0) {
            ((void (*)(s32))func_80178D18)(a0);
            *(u16 *)((char *)a0 + 0x2) = 1;
            *(u16 *)((char *)a0 + 0x34) = 0;
        }
        break;
    case 3:
        ((s32 (*)(s32))func_80178970)(a0);
        *(s32 *)((char *)a0 + 0x1C) = 0;
        break;
    case 4:
        ((s32 (*)(s32))func_80178970)(a0);
        p = *(s32 **)((char *)a0 + 0x20);
        *(u16 *)((char *)p + 0x12) = *(u16 *)((char *)p + 0x12) - 0x20;
        t = *(s32 *)((char *)a0 + 0x1C) + 1;
        *(s32 *)((char *)a0 + 0x1C) = t;
        if (t >= 0x30) {
            *(u16 *)((char *)a0 + 0x34) = 5;
        }
        break;
    case 5:
        if (((s32 (*)(s32))func_80178970)(a0) != 0) {
            ((void (*)(s32))func_80178D18)(a0);
            func_80186D7C(a0);
        }
        break;
    }
}
