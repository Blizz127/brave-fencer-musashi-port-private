/* sc01_0077: func_801588CC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 D_801D9658;
extern s32 D_801D9664;
extern s32 D_801D9668;
extern int D_801D9658;
extern int D_801D9664;
extern int D_801D9668;
extern int func_800D0CA0(int);
extern int func_8001AAA0(int);
extern int func_8001BD80(void);
extern s32 func_80159464(void);
s32 func_80159464(void);

void func_801588CC(int param_1) {
    extern void (*D_80188EBC[])(void);
    extern int D_801D965C;
    extern int D_801D9660;
    short sVar1;
    D_80188EBC[*(unsigned short *)(param_1 + 2)]();
    switch (D_801D9658) {
    case 0:
        break;
    case 1:
        func_800D0CA0(2);
        D_801D9660 = 0;
        D_801D965C = 0x46;
        D_801D9658 += 1;
        break;
    case 2:
        if (D_801D965C == 0) {
            if (func_8001BD80() == 0) {
                D_801D9658 += 1;
            }
        } else {
            D_801D965C -= 1;
        }
        break;
    case 3:
        if (func_8001AAA0(0x83) != 0) {
            D_801D9658 += 1;
        }
        break;
    case 4:
        D_801D9664 = 0;
        sVar1 = ((int (*)(int))func_80159464)(param_1);
        if (sVar1 != 0) {
            D_801D965C = 0xd2;
        } else {
            D_801D965C = 1;
        }
        break;
    case 5:
        D_801D965C -= 1;
        if (D_801D965C == -1 || D_801D9668 != 0) {
            D_801D965C = 0;
            D_801D9658 += 1;
        }
        break;
    case 6:
        func_800D0CA0(1);
        D_801D965C = 0x28;
        D_801D9658 += 1;
        break;
    case 7:
        if (D_801D965C == 0) {
            if (func_8001BD80() == 0) {
                D_801D9658 += 1;
            }
        } else {
            D_801D965C -= 1;
        }
        break;
    case 8:
        D_801D9660 = 1;
        break;
    }
}
