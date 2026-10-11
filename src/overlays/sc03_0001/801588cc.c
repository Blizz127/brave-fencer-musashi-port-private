/* sc03_0001: func_801588CC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 D_801ED518;
extern s32 D_801ED524;
extern s32 D_801ED528;
extern int D_801ED518;
extern int D_801ED524;
extern int D_801ED528;
extern int func_800D0CA0(int);
extern int func_8001AAA0(int);
extern int func_8001BD80(void);
extern s32 func_80159464(void);
s32 func_80159464(void);

void func_801588CC(int param_1) {
    extern void (*D_8018F8AC[])(void);
    extern int D_801ED51C;
    extern int D_801ED520;
    short sVar1;
    D_8018F8AC[*(unsigned short *)(param_1 + 2)]();
    switch (D_801ED518) {
    case 0:
        break;
    case 1:
        func_800D0CA0(2);
        D_801ED520 = 0;
        D_801ED51C = 0x46;
        D_801ED518 += 1;
        break;
    case 2:
        if (D_801ED51C == 0) {
            if (func_8001BD80() == 0) {
                D_801ED518 += 1;
            }
        } else {
            D_801ED51C -= 1;
        }
        break;
    case 3:
        if (func_8001AAA0(0x83) != 0) {
            D_801ED518 += 1;
        }
        break;
    case 4:
        D_801ED524 = 0;
        sVar1 = ((int (*)(int))func_80159464)(param_1);
        if (sVar1 != 0) {
            D_801ED51C = 0xd2;
        } else {
            D_801ED51C = 1;
        }
        break;
    case 5:
        D_801ED51C -= 1;
        if (D_801ED51C == -1 || D_801ED528 != 0) {
            D_801ED51C = 0;
            D_801ED518 += 1;
        }
        break;
    case 6:
        func_800D0CA0(1);
        D_801ED51C = 0x28;
        D_801ED518 += 1;
        break;
    case 7:
        if (D_801ED51C == 0) {
            if (func_8001BD80() == 0) {
                D_801ED518 += 1;
            }
        } else {
            D_801ED51C -= 1;
        }
        break;
    case 8:
        D_801ED520 = 1;
        break;
    }
}
