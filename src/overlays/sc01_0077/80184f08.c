/* sc01_0077: func_80184F08 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
typedef struct { u8 b[8]; } S8_80184F08;
typedef struct { short vx, vy, vz, pad; } SVECTOR_80184F08;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern u8 D_801152A8[];
extern u8 D_801152A8[];
extern s32 func_80134510(s32 arg);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_80049A1C(void *a0, void *a1);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_80017E68(void *a0, void *a1);
extern void func_800D23D0(void *a0);
extern s32 func_80017DC4(void *a0, void *a1);
extern void func_800D20C0();
extern void func_8012A568(void (*a0)(void));
extern void func_8012C218(void *a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern void func_8012A828(int, void *);
extern void func_8012A828(int a0, void *a1);
extern void func_8012C218(void *a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012C218(void *a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012A828(int, void *);
extern s32 D_801DA908;

s32 func_80184F08(s32 param_1) {
    extern s32 func_8012C354(s32 a0, s32 a1);
    extern void func_8004A27C(s32, void *);
    extern void func_8004818C(s32, void *, s32);
    extern s32 D_8019918C;
    extern char * D_801991C0;
    extern char D_801DA8E8[];
    S8_80184F08 s60;
    SVECTOR_80184F08 sStack_58;
    S8_80184F08 s50;
    int auStack_48[8];
    s32 iVar5, iVar8;
    char *puVar2, *puVar4;
    u16 uVar3;
    if (((s32 (*)(s32, void *))func_8012C354)(param_1, &D_8019918C) == 0) {
        ((void (*)(s32))func_8012C218)(param_1);
    }
    ((void(*)(s32, void *))func_8012A828)(param_1, &(*(s32 *)&D_80186E48));
    iVar5 = *(s32 *)(param_1 + 0x20);
    *(s16 *)(param_1 + 0x70) = 0x80;
    *(s32 *)(iVar5 + 4) |= 0x50000040;
    *(u16 *)(iVar5 + 0x2c) |= 1;
    iVar8 = *(s32 *)(*(s32 *)(param_1 + 0x64) + 0x20) + 0x34;
    ((void (*)(s32, s32, void *))func_8012F14C)(iVar8, D_801DA908, &s60);
    s50 = s60;
    sStack_58.vz = 0x1800;
    sStack_58.vy = 0x1800;
    sStack_58.vx = 0x1800;
    ((void (*)(void *, void *))func_80017DC4)(&sStack_58, auStack_48);
    func_8004A27C(func_8005C49C() & 0xfff, auStack_48);
    func_8004818C(iVar8, auStack_48, iVar5 + 0x34);
    ((void (*)(void *, s32))func_80017E68)(&s50, iVar5 + 0x34);
    {
        register char *tmp __asm__("$2");
        tmp = D_801991C0;
        puVar2 = tmp;
    }
    puVar4 = puVar2 + 0x20;
    D_801991C0 = puVar4;
    *(char **)(param_1 + 0xcc) = puVar2;
    if (D_801DA8E8 < puVar4) {
        D_801991C0 = D_801DA8E8 - 0x120;
    }
    func_800D20C0(&s60, &sStack_58, 7);
    func_800D23D0(&sStack_58);
    ((void(*)(void *, void *))func_80049A1C)(&sStack_58, puVar2);
    ((void (*)(void *, s32))func_80017E68)(&s60, (s32)puVar2);
    uVar3 = *(u16 *)((char *)&s50 + 2);
    if (((s32 (*)(void *))func_80134510)(&s50) != 0 &&
        (s32)(s16)uVar3 - (s32)*(s16 *)((char *)&s50 + 2) < 0x80) {
        *(s16 *)((char *)&s50 + 2) = *(s16 *)((char *)&s50 + 2) - 4;
        {
            register char *tmp __asm__("$3");
            tmp = D_801991C0;
            puVar2 = tmp;
        }
        puVar4 = puVar2 + 0x20;
        D_801991C0 = puVar4;
        *(char **)(param_1 + 0xd0) = puVar2;
        if (D_801DA8E8 < puVar4) {
            D_801991C0 = D_801DA8E8 - 0x120;
        }
        func_800D23D0(&(*(s32 *)&D_801152A8));
        ((void(*)(void *, void *))func_80049A1C)(&(*(s32 *)&D_801152A8), puVar2);
        ((void (*)(void *, s32))func_80017E68)(&s50, (s32)puVar2);
    }
    *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
}
