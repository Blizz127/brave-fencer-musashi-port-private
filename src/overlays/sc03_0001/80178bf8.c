/* sc03_0001: func_80178BF8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80016714(void *a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_80016714(void *, s32);
extern short D_801EF464;
extern s32 D_801EE5E0;
extern s32 D_801EF2E0;

s32 func_80178BF8()
{
    extern void func_8017B1D8(void);
    extern short D_801EF464;
    extern int D_801EE5E0;
    extern short D_801EE5F0;
    extern short D_801EE5EC;
    extern short D_801EE5E8;
    extern short D_801EE5E4;
    extern int D_801EF2E0;
    extern int D_801EE5F8;
    extern s16 D_801EE5D8;
    extern short D_801EE5D0;
    extern short D_801EE5D4;
    extern int D_801EF3A8;
    extern unsigned int D_801EE648;
    extern unsigned short D_801EE5CE;
    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;
    iVar2 = 9;
    puVar3 = &D_801EE648;
    D_801EF464 = 0;
    D_801EE5E0 = 0;
    D_801EE5F0 = 0;
    D_801EE5EC = 0;
    D_801EE5E8 = 0;
    D_801EE5E4 = 0;
    D_801EF2E0 = 1;
    D_801EE5F8 = 0;
    (*(short *)&D_801EE5D8) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_801EE5CE;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_801EE5D0 = 0;
    D_801EE5D4 = 0;
    ((void (*)(int *, int))func_80016714)(&D_801EF3A8, 0x14);
    func_8017B1D8();
}
