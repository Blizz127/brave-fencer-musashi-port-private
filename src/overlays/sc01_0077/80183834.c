/* sc01_0077: func_80183834 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183324.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012C218(void *a0);
extern s32 D_801270CC;
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8004CFEC(s32, s32);
extern s16 D_8018AACC;
extern s16 D_8018AAD0;
extern void func_8012A828(int, void *);
extern void func_8012B2CC(int);
extern void func_8012B23C(int);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012B23C(s32 a0);
extern void func_8012B2CC(int a0);
extern void func_8012B23C(int a0);
extern void func_8012A828(int a0, void *a1);
extern void func_8012B2CC(s32);
extern void func_8012B23C(s32);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8005C49C(void);
extern void func_80181F08(void);
extern s32 D_801270D8;
extern s16 D_8018AACC;
extern s16 D_8018AAD0;
extern s32 func_8004CFEC(s32, s32);
extern s32 func_8005C49C(void);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern u8 D_8018AB18[];
extern u8 D_801B0330[];
extern void (*D_8018ADC4[])();
extern s32 func_8012C044(s32 a0);
extern void func_8012C098(void);
extern void func_8012C218(void *a0);
extern s32 D_801270CC;

void func_80183834(s32 param_1) {
    s32 obj;
    s32 ang;
    u16 t;
    if ((*(u16 *)(param_1 + 0x5C) & 1) != 0) {
        func_80181F08();
    }
    if ((*(u16 *)(param_1 + 0x70) & 0x400) != 0 && D_801270D8 != 0 &&
        *(u16 *)(param_1 + 0x2) != 0xA) {
        *(u16 *)(param_1 + 0x2) = 0xA;
        *(u16 *)(param_1 + 0x98) = 0;
        *(s32 *)(param_1 + 0x1C) = 0x3C;
        *(u16 *)(param_1 + 0x5C) = 0;
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x12) =
            ((((func_8004CFEC(*(s16 *)(param_1 + 0xE) - D_8018AAD0,
                       D_8018AACC - *(s16 *)(param_1 + 0x6)) -
                0x400) &
               0xFFF) +
              0x800) &
             0xFFF);
        if (*(s16 *)(param_1 + 0x6) > 0x180) {
            obj = *(s32 *)(param_1 + 0x20);
            ang = *(s16 *)(obj + 0x12);
            *(u16 *)(obj + 0x12) = (func_8005C49C() & 1) ? ang - 0x400 : ang + 0x400;
        }
        func_8012B2CC(param_1);
        func_8012B23C(param_1);
        func_8012B14C(param_1, (s32)&D_8018AB18);
        func_8012A828(param_1, &D_801B0330);
    }
    if (*(u16 *)param_1 != 0x2F) {
        return;
    }
    D_8018ADC4[*(u16 *)(param_1 + 0x2)](param_1);
    *(u16 *)(param_1 + 0xDE) = *(u16 *)(param_1 + 0xDE) + 1;
    t = *(u16 *)(param_1 + 0x86);
    if (t != 0) {
        *(u16 *)(param_1 + 0x86) = t - 1;
        if (*(u16 *)(param_1 + 0x86) != 0) {
            return;
        }
    }
    if (func_8012C044(param_1) == 0) {
        return;
    }
    switch ((s32)((u32)*(u16 *)(param_1 + 0x70) << 0x10) >> 0x18) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
        ((void (*)(s32))func_8012C098)(param_1);
        return;
    case 3:
    case 7:
        ((void (*)(s32))func_8012C218)(param_1);
        return;
    case 4:
        D_801270CC = D_801270CC - 1;
        ((void (*)(s32))func_8012C218)(param_1);
        return;
    }
}
