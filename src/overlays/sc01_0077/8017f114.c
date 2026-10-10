/* sc01_0077: func_8017F114 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern u16 D_800B99DA;
extern u16 D_80126B66;
extern void func_8012A568(void (*a0)(void));
extern u16 D_80126B66;
extern u16 D_80126B66;
extern u16 D_80126B66;
extern void func_8002D4C8(s32 a0, s32 a1);
extern unsigned short D_800B99DA;
extern u16 D_80126B66;
extern short D_8018A858;
extern void func_8002D4C8(int, int);

void func_8017F114(void)
{
    int iVar1;
    int iVar5;
    int iVar7;
    int iVar8;
    register short *psVar6 __asm__("$7");
    register short *psVar2 __asm__("$4");
    register int uVar4 __asm__("$5");
    int uVar3;
    register int num __asm__("$2");
    uVar4 = 0;
    if ((D_800B99DA & 4) == 0) {
        iVar1 = (int)(*(short *)&D_80126B66);
        psVar6 = &D_8018A858;
        iVar8 = 0;
        psVar2 = psVar6 + 3;
        do {
            iVar7 = (int)psVar6[0];
            if (iVar1 < iVar7) goto cont;
            iVar5 = (int)psVar2[-2];
            if (iVar1 < iVar5) goto adjA;
            iVar7 = (int)psVar2[-1];
            if (iVar1 < iVar7) goto set7f;
            iVar5 = (int)psVar2[0];
            if (iVar1 < iVar5) goto adjC;
cont:
            iVar8 = iVar8 + 1;
            psVar2 = psVar2 + 4;
            psVar6 = psVar6 + 4;
        } while (iVar8 < 2);
post:
        if (uVar4 > 0) goto clamp;
        uVar3 = 4;
        uVar4 = 0x499;
        goto call;
adjC: iVar1 = iVar5 - iVar1; goto divide;
set7f: uVar4 = 0x7f; goto post;
adjA: iVar1 = iVar1 - iVar7;
divide:
        num = iVar1 * 0x7f;
        iVar1 = iVar5 - iVar7;
        uVar4 = num / iVar1;
        goto post;
clamp:
        uVar3 = 0x499;
        if (0x7f < uVar4) uVar4 = 0x7f;
        uVar4 = (uVar4 | 0x1000) & 0xffff;
call:
        func_8002D4C8(uVar3, uVar4);
    }
    return;
}
