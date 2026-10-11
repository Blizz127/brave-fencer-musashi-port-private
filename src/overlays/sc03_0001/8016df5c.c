/* sc03_0001: func_8016DF5C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { s32 w[8]; } Blk20;
typedef struct { s32 w[8]; } Blk20_8016DF5C;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_801465C0(void);
extern s32 D_8011D030;
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern Blk20 D_800AE620;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_800233CC(void *, unsigned short);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_80146C3C(void);
extern Blk20 D_800AE620;
extern void func_801465C0(void);
extern void func_800233CC(void*, unsigned short);
extern int func_8005C49C(void);
extern void func_80048FBC(void *a, void *b, void *c);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_800233CC(void*, unsigned short);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_80146C3C(void);
extern void func_80146C3C();
extern s32 D_8011D030;
extern void func_80146C3C(void);
extern void func_80146C3C();
extern Blk20 D_800AE620;
extern s32 D_8011D030;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_80146C3C(void);

void func_8016DF5C(s32 param_1)
{
    extern void func_8016E3CC(void *a0);
    extern void func_8004A0DC(s32 a0, void *a1);
    extern u8 D_801EE188;
    extern u8 D_801EE189;
    extern u8 D_801EE18A;
    extern u8 D_801EE18C;
    extern u8 D_801EE18D;
    extern u8 D_801EE18E;
    s32 iVar8;
    short sVar1;
    iVar8 = *(s32 *)((u8 *)((void *)param_1) + 0x34);
    if ((*(u32 *)((u8 *)((void *)param_1) + 0x2c) & 0x8000) == 0) {
        unsigned short uVar7 = 0;
        u16 *psVar6 = (u16 *)&D_8011D030;
        s32 iNew;
        s32 base;
        do {
            if (psVar6 != (u16 *)((void *)param_1) && (*psVar6 == 0x41 || *psVar6 == 0x48)) {
                ((void (*)(void *))func_80146C3C)(psVar6);
            }
            uVar7++;
            psVar6 += 0x2c;
        } while (uVar7 < 0x1e);
        iNew = ((s32(*)())func_801465C0)();
        if (iNew == 0) {
            return;
        }
        base = (s32)&D_801EE188;
        D_801EE18A = 0xc0;
        *(u8 *)base = 0xc0;
        D_801EE189 = 0;
        D_801EE18E = 0;
        D_801EE18D = 0;
        D_801EE18C = 0;
        ((void(*)(void *, unsigned short))func_800233CC)((void *)base, 0x40);
        func_8001CD50(iNew, base);
        *(s32 *)(iNew + 0x34) = (s32)((u8 *)((void *)param_1) + 0x38);
        *(s16 *)(iNew + 0x1a) = 0;
        *(s16 *)(iNew + 0x18) = 0;
        *(u32 *)(iNew + 4) = *(u32 *)(iNew + 4) | 0x50000000;
        func_8016E3CC(((void *)param_1));
        {
            register s32 t10 __asm__("$3");
            t10 = 0x10;
            *(s32 *)((u8 *)((void *)param_1) + 0x20) = iNew;
            *(s32 *)((u8 *)((void *)param_1) + 0x1c) = t10;
        }
        sVar1 = *(u16 *)((u8 *)((void *)param_1) + 2) + 1;
    } else {
        short asStack_60[20];
        Blk20_8016DF5C localMatrix;
        s32 uVar2;
        asStack_60[0] = 0;
        asStack_60[1] = 0;
        asStack_60[2] = 0x20;
        localMatrix = (*(Blk20_8016DF5C*)&D_800AE620);
        uVar2 = ((s32(*)())func_8005C49C)();
        func_8004A0DC((uVar2 & 0x7f00) >> 3, &localMatrix);
        func_80048FBC(&localMatrix, asStack_60, asStack_60);
        *(s16 *)((u8 *)((void *)param_1) + 6) = D_80126B5E + asStack_60[0];
        *(s16 *)((u8 *)((void *)param_1) + 0xa) = D_80126B62 - ((u16)uVar2 & 0x3f);
        *(s16 *)((u8 *)((void *)param_1) + 0xe) = D_80126B66 + asStack_60[2];
        *(Blk20_8016DF5C *)((u8 *)((void *)param_1) + 0x38) = *(Blk20_8016DF5C *)((u8 *)iVar8 + 0x38);
        *(s32 *)((u8 *)((void *)param_1) + 0x2c) = 0x1000;
        *(s32 *)((u8 *)((void *)param_1) + 0x30) = 0xff;
        *(s32 *)((u8 *)((void *)param_1) + 0x1c) = 0x10;
        __asm__ __volatile__("" ::: "memory");
        sVar1 = 4;
    }
    *(s16 *)((u8 *)((void *)param_1) + 2) = sVar1;
}
