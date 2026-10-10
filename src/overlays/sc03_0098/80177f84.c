/* sc03_0098: func_80177F84 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

void func_80177F84(s32 param_1, s32 param_2) {
    u16 uVar4;
    s16 iVar3;
    register u8 *pcVar2 __asm__("$6");
    u32 uVar1;
    s32 c5;
    s32 cmask;
    uVar4 = 0x100;
    iVar3 = 0;
    c5 = 5;
    cmask = -257;
    pcVar2 = (u8 *)(param_1 + 0xc);
    do {
        register u32 src __asm__("$2");
        register u32 byteval __asm__("$3");
        register u32 testval __asm__("$4");
        src = (param_2 >> 0x10) & 0xf;
        byteval = src;
        __asm__ __volatile__("" : "=r"(byteval) : "0"(byteval));
        testval = src;
        param_2 = param_2 << 4;
        if ((iVar3 == c5) || (testval != 0)) {
            uVar4 = 0;
        }
        pcVar2 += 0x14;
        iVar3 += 1;
        {
            register s32 r __asm__("$4");
            r = *(u16 *)(pcVar2 - 2);
            pcVar2[0] = (u8)(byteval * 8 + 8);
            *(u16 *)(pcVar2 - 2) = uVar4 | (r & cmask);
        }
    } while (iVar3 < 5);
}
