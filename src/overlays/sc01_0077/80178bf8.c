/* sc01_0077: func_80178BF8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80016714(void *a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_80016714(void *, s32);
extern short D_801DAB2C;
extern s32 D_801DA720;
extern s32 D_801DA9B0;

void func_80178BF8(s32 _unused0, s32 _unused1)
{
    extern void func_8017B1D8(void);
    extern short D_801DAB2C;
    extern int D_801DA720;
    extern short D_801DA730;
    extern short D_801DA72C;
    extern short D_801DA728;
    extern short D_801DA724;
    extern int D_801DA9B0;
    extern int D_801DA738;
    extern s16 D_801DA718;
    extern short D_801DA710;
    extern short D_801DA714;
    extern int D_801DAA88;
    extern unsigned int D_801DA788;
    extern unsigned short D_801DA70E;
    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;
    iVar2 = 9;
    puVar3 = &D_801DA788;
    D_801DAB2C = 0;
    D_801DA720 = 0;
    D_801DA730 = 0;
    D_801DA72C = 0;
    D_801DA728 = 0;
    D_801DA724 = 0;
    D_801DA9B0 = 1;
    D_801DA738 = 0;
    (*(short *)&D_801DA718) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_801DA70E;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_801DA710 = 0;
    D_801DA714 = 0;
    ((void (*)(int *, int))func_80016714)(&D_801DAA88, 0x14);
    func_8017B1D8();
}
