/* sc03_0001: func_8018CCB0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012AD50(void *arg0);
void func_8018CBB0(s32 param_1, s32 param_2);
extern void func_8018CBB0(s32, s32);
extern s32 func_8012AD50(void *a0);

void func_8018CCB0(int param_1) {
    short uVar1;
    *(short *)(param_1 + 0xfc) = 0;
    *(int *)(param_1 + 0x1c) = 1;
    uVar1 = *(unsigned short *)(param_1 + 0x70) & 7;
    *(short *)(param_1 + 0xfe) = (uVar1 < 2) ? 0x1e : 0xf;
    if (uVar1 != 0) {
        func_8018CBB0(param_1, -0x80);
        func_8018CBB0(param_1, -0x30);
        func_8018CBB0(param_1, 0x20);
        func_8018CBB0(param_1, 0x70);
        func_8018CBB0(param_1, 0xc0);
    }
    if (1 < uVar1) {
        func_8018CBB0(param_1, -0x58);
        func_8018CBB0(param_1, -0x8);
        func_8018CBB0(param_1, 0x48);
        func_8018CBB0(param_1, 0x98);
        func_8018CBB0(param_1, 0xe8);
    }
    ((void (*)(int))func_8012AD50)(param_1);
}
