/* SC02.CD member35: func_80178BF8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80016714(void *a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_80016714(void *, s32);
extern short D_801BEA44;
extern s32 D_801BE838;
extern s32 D_801BE8EC;
extern s32 D_801BE420;

s32 func_80178BF8()
{
    extern void func_8017B1D8(void);
    extern short D_801BEA44;
    extern int D_801BE838;
    extern short D_801BE848;
    extern short D_801BE844;
    extern short D_801BE840;
    extern short D_801BE83C;
    extern int D_801BE8EC;
    extern int D_801BE850;
    extern s16 D_801BE830;
    extern short D_801BE828;
    extern short D_801BE82C;
    extern int D_801BE9A0;
    extern unsigned int D_801BE8A0;
    extern unsigned short D_801BE826;
    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;
    iVar2 = 9;
    puVar3 = &D_801BE8A0;
    D_801BEA44 = 0;
    D_801BE838 = 0;
    D_801BE848 = 0;
    D_801BE844 = 0;
    D_801BE840 = 0;
    D_801BE83C = 0;
    D_801BE8EC = 1;
    D_801BE850 = 0;
    (*(short *)&D_801BE830) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_801BE826;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_801BE828 = 0;
    D_801BE82C = 0;
    ((void (*)(int *, int))func_80016714)(&D_801BE9A0, 0x14);
    func_8017B1D8();
}
extern s32 D_801BE420;
