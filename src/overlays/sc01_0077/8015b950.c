/* sc01_0077: func_8015B950 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
struct S_80149744;
struct S_80149744 {
    char pad44[0x44];
    s32 w44;
    char pad48[0xAC - 0x48];
    u16 h_AC;
};
extern s32 func_80161CD0(s32 a0, s32 a1);
extern s32 func_80029178(s32 arg);
extern void func_80146D90(s32 a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_801488A8(u8 *a0);
extern int func_80148AFC(void *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149704(void);
extern s32 func_80149744(struct S_80149744 *a0);
extern void func_80149788(void);
extern s32 func_8016F1AC(void);
extern s32 func_80149AA8(s32 *a0);
extern s32 func_80149B54(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern s32 func_80149B54(s32 * arg0);
extern void func_80149BAC(s32 *a0);
extern s32 func_80029178(s32 a0);
extern s32 func_80149CD4(s32 a0);
extern s32 func_80013294(void *a0, void *a1);
void func_80146D90(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801541D8(u8 *a0, s32 a1, s32 a2);
extern s32 func_80029178(s32);
extern s32 func_80161208();
extern void func_8015E880(s32 *a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_801725A4(u8 *a0);
extern void func_80146D90(int);
extern void (*D_801891B8[])(void *);
extern void func_80159B70(void *a0);
extern void func_8015A264(void *a0);
extern s32 D_8011F9C4;
extern s32 func_80161CD0(s32 a0, s32 a1);
extern M2C_UNK D_8018914C;
extern void (*D_801891B8[])(void *);
extern s32 func_801619A4(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_800CCCC0(s32 a0);
extern int func_80148AFC(void *a0);
extern void func_80146D90(s32 a0);
extern void func_801541D8(u8 *a0, s32 a1, s32 a2);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_801725A4(u8 *a0);
extern s32 func_80149AA8(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_80149B54(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void (*D_801891B8[])(void *);
extern s32 D_8011F9C4;
extern s32 D_8018914C;
extern s32 func_80161B18(void);
extern s32 func_801619A4(s32*);
extern s32 func_80149AA8(s32*);
extern void func_80149AD4(s32*);
extern s32 func_80149B54(s32*);
extern void func_80149BAC(s32*);
extern s32 func_801498E0(s32*);
extern s32 func_80149954(s32);
extern s32 func_80149A64(s32*);
extern void func_800CCCC0(s32 a0);
extern s32 func_80149CD4(s32 a0);
extern void func_8015E880(s32*);
extern s32 func_80149744(struct S_80149744*);
extern void func_80149788(void);
extern s32 func_801496D4(void*);
extern void func_80149704(void);
extern int func_80148AFC(void*);
extern void func_80146D90(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801541D8(u8*, s32, s32);
extern s32 func_801488A8(u8*);
extern void func_80147078(s32*, s16);
extern void func_8015A264(void*);
extern s32 func_80013294(void*, void*);
extern void func_80159B70(void*);
extern s32 func_8016F1AC(void);
extern s32 func_80029178(s32 a0);
extern void func_80146DB8(s32*, s32*);
extern s32 func_80161CD0(s32, s32);
extern s32 func_80161208(s32 a0);
extern s32 func_801725A4(u8*);

s32 func_8015B950(s32 arg0)
{
    s16 sp10[4];
    s16 sp18[4];
    s32 t;
    s32 z;
    s32 doit;
    s32 lim = -0xB0000;
    if (func_80161B18() != 0) {
        return;
    }
    switch (((s32 (*)(s32))func_801619A4)(arg0)) {
    case 0:
    case 1:
    case 2:
    case 6:
        if (((s32 (*)(s32))func_80149AA8)(arg0) != 0) {
            D_801891B8[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_80149AD4)(arg0);
            return;
        }
        if (((s32 (*)(s32))func_80149B54)(arg0) != 0) {
            D_801891B8[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_80149BAC)(arg0);
            return;
        }
        break;
    case 3:
        ((void (*)(s32))func_801498E0)(arg0);
        break;
    case 4:
        ((void (*)(s32))func_80149954)(arg0);
        break;
    case 5:
        if (((s32 (*)(s32))func_80149A64)(arg0) != 0) {
            D_801891B8[*(u16 *)arg0]((void *)arg0);
            func_800CCCC0(arg0);
            return;
        }
        break;
    }
    if (func_80149CD4(arg0) != 0) {
        D_801891B8[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_8015E880)(arg0);
        return;
    }
    if (((s32 (*)(s32))func_80149744)(arg0) != 0) {
        D_801891B8[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_80149788)(arg0);
        return;
    }
    if (((s32 (*)(s32))func_801496D4)(arg0) != 0) {
        D_801891B8[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_80149704)(arg0);
        if (((u8)((s32 (*)(s32))func_80148AFC)(arg0)) == 0) {
            func_80146D90(arg0);
        }
        if ((*(s32 *)(arg0 + 0x24) | *(s32 *)(arg0 + 0x2C)) != 0) {
            func_80154150(arg0, 0xF);
        } else {
            ((void (*)(s32, s32, s32))func_801541D8)(arg0, 0xD, 6);
        }
        *(s32 *)(arg0 + 0x238) = 1;
        return;
    }
    if (((s32 (*)(s32))func_801488A8)(arg0) != 0) {
        sp10[0] = 0;
        sp10[1] = 0;
        sp10[2] = 0;
        t = *(s16 *)(arg0 + 0x26);
        sp18[0] = t;
        sp18[1] = 0;
        t = *(s16 *)(arg0 + 0x2E);
        sp18[2] = t;
        D_801891B8[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32, s32))func_80147078)(arg0, 1);
        ((void (*)(s32))func_8015A264)(arg0);
        t = -(((s32 (*)(s16 *, s16 *))func_80013294)(sp10, sp18) << 0x10);
        if (t < *(s32 *)(arg0 + 0x2C)) {
            *(s32 *)(arg0 + 0x2C) = t;
        }
        return;
    }
    if (*(u16 *)(arg0 + 0xB8) == 0x8000) {
        D_801891B8[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32, s32))func_80147078)(arg0, 0);
        ((void (*)(s32))func_80159B70)(arg0);
        return;
    }
    z = *(s32 *)(arg0 + 0x2C);
    if (func_8016F1AC() != 0) {
        goto zero;
    }
    if (z <= lim) {
        goto one;
    }
    if (D_8011F9C4 == 0) {
        goto zero;
    }
    if (((u8)func_80029178(0x21)) != 0) {
        goto zero;
    }
one:
    doit = 1;
    goto join;
zero:
    doit = 0;
join:
    if (doit != 0) {
        D_801891B8[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32, s32))func_80147078)(arg0, 0);
        ((void (*)(s32))func_80159B70)(arg0);
        func_80154150(arg0, 9);
        ((void (*)(s32, s32 *))func_80146DB8)(arg0, &D_8018914C);
        ((void (*)(s32, s32))func_80161CD0)(arg0, *(u16 *)(arg0 + 0x16E));
        return;
    }
    if (func_80161208(arg0) == 0) {
        ((void (*)(s32))func_801725A4)(arg0);
    }
}
