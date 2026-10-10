/* sc01_0077: func_8012DBD0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_8012DE2C(s32 a0);
extern s32 func_8012DDA4(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80013350(s32 a0, void *a1);
extern s32 func_8012DE2C(s32 a0);
extern s32 func_8012DDA4(void);
extern void func_80013350(s32 a0, void *a1);
s32 func_8012DDA4();
s32 func_8012DE2C(s32 a0);

s32 func_8012DBD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 param_1;
    s32 param_2;
    register s32 param_3 __asm__("$21");
    register s32 param_4 __asm__("$19");
    s32 iVar1;
    s32 iVar5;
    s32 iVar4;
    register s32 t __asm__("$2");
    u32 uVar3;
    param_1 = arg0;
    param_2 = arg1;
    param_3 = arg2;
    param_4 = arg3;
    iVar1 = func_8012DE2C(param_1);
    if (iVar1 == 0) {
        return 0;
    }
    if (*(u32 *)(param_1 + 0x58) == 0) {
        iVar5 = 0x80;
    } else {
        uVar3 = *(u32 *)(param_1 + 0x58) & 0xfffffff;
        t = (s32)*(s16 *)(uVar3 + 4);
        iVar4 = (s32)*(s16 *)(uVar3 + 6);
        iVar5 = t;
        if (t < 0) {
            iVar5 = -iVar5;
        }
        if (iVar4 < 0) {
            iVar4 = -iVar4;
        }
        __asm__ __volatile__("" : "=r"(iVar4) : "0"(iVar4));
        if (iVar5 < iVar4) {
            iVar5 = iVar4;
        }
        t = (s32)*(s16 *)(uVar3 + 8);
        iVar4 = t;
        if (t < 0) {
            iVar4 = -iVar4;
        }
        if (iVar5 < iVar4) {
            iVar5 = iVar4;
        }
        t = (s32)*(s16 *)(uVar3 + 10);
        iVar4 = t;
        if (t < 0) {
            iVar4 = -iVar4;
        }
        if (iVar5 < iVar4) {
            iVar5 = iVar4;
        }
        t = (s32)*(s16 *)(uVar3 + 0xc);
        iVar4 = t;
        if (t < 0) {
            iVar4 = -iVar4;
        }
        if (iVar5 < iVar4) {
            iVar5 = iVar4;
        }
        t = (s32)*(s16 *)(uVar3 + 0xe);
        iVar4 = t;
        if (t < 0) {
            iVar4 = -iVar4;
        }
        if (iVar5 < iVar4) {
            iVar5 = iVar4;
        }
    }
    iVar5 = iVar5 * iVar5;
LAB_8012dcf8:
    do {
        u16 uVar6 = *(u16 *)(iVar1 + 0x5c);
        if ((uVar6 & 0x8000) != 0) {
            if ((uVar6 & 0x4000) == 0) {
                if (*(u16 *)(iVar1 + 0x5e) != param_4) {
                    if ((*(u16 *)(iVar1 + 0xae) & 1) == 0) {
                        if (((s32(*)(s32, s32))func_80013350)(param_1 + 4, iVar1 + 4) < iVar5) {
                            *(u16 *)(iVar1 + 0x60) = param_2;
                            *(u16 *)(iVar1 + 0x62) = param_3;
                            *(u16 *)(iVar1 + 0x5e) = param_4;
                            *(u16 *)(iVar1 + 0x5c) = *(u16 *)(iVar1 + 0x5c) | 1;
                        }
                    }
                }
            }
        }
        iVar1 = func_8012DDA4();
    } while (iVar1 != 0);
    return 0;
}
