/* sc03_0098: func_80178BF8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80016714(void *a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_80016714(void *, s32);
extern short D_801C58B4;
extern s32 D_801C5428;
extern s32 D_801C575C;

s32 func_80178BF8()
{
    extern void func_8017B1D8(void);
    extern short D_801C58B4;
    extern int D_801C5428;
    extern short D_801C5438;
    extern short D_801C5434;
    extern short D_801C5430;
    extern short D_801C542C;
    extern int D_801C575C;
    extern int D_801C5440;
    extern s16 D_801C5420;
    extern short D_801C5418;
    extern short D_801C541C;
    extern int D_801C5810;
    extern unsigned int D_801C5490;
    extern unsigned short D_801C5416;
    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;
    iVar2 = 9;
    puVar3 = &D_801C5490;
    D_801C58B4 = 0;
    D_801C5428 = 0;
    D_801C5438 = 0;
    D_801C5434 = 0;
    D_801C5430 = 0;
    D_801C542C = 0;
    D_801C575C = 1;
    D_801C5440 = 0;
    (*(short *)&D_801C5420) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_801C5416;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_801C5418 = 0;
    D_801C541C = 0;
    ((void (*)(int *, int))func_80016714)(&D_801C5810, 0x14);
    func_8017B1D8();
}
