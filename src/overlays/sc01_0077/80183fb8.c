/* sc01_0077: func_80183FB8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
typedef struct { u8 b[8]; } Blk8;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012CBA4(s32 a0);
extern s32 func_8012CBA4(s32);
extern void func_8002D4C8(s32, s32);
extern s32 func_8012CBA4();
void func_8018414C(short *param_1);
void func_80184238(void *a0);
void func_80184254(s32 a0);

void func_80183FB8(int param_1) {
    extern s32 D_8018AE80;
    extern s32 D_8018AE84;
    extern void func_80184254(s32 a0);
    extern void func_80184238(void *a0);
    int iVar4;
    int a3;
    int src;
    short sVar3;
    ((void (*)(void))func_8012CBA4)();
    iVar4 = *(int *)(param_1 + 0xdc) + D_8018AE84;
    *(int *)(param_1 + 0xdc) = iVar4;
    if (D_8018AE80 < iVar4) {
        *(int *)(param_1 + 0xdc) = D_8018AE80;
    }
    if (*(unsigned short *)(param_1 + 0x34) == 0) {
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0xdc);
    } else {
        *(int *)(param_1 + 0x18) = -*(int *)(param_1 + 0xdc);
    }
    if (0x600000 < *(int *)(param_1 + 0x14)) {
        *(int *)(param_1 + 0x14) = 0x600000;
    }
    a3 = *(int *)(param_1 + 0xcc);
    if (a3 != 0) {
        *(unsigned short *)(a3 + 0x18) = 0x1800;
        *(unsigned short *)(a3 + 0x2c) |= 0x10;
        src = *(int *)(param_1 + 0x20);
        *(Blk8 *)(a3 + 8) = *(Blk8 *)(src + 8);
        *(unsigned short *)(a3 + 0xa) -= 0x10;
        *(unsigned short *)(a3 + 0x10) = *(unsigned short *)(a3 + 0x10) + *(short *)(param_1 + 0x1a) * -0x10;
    }
    sVar3 = *(unsigned short *)(param_1 + 0x84) + 1;
    *(unsigned short *)(param_1 + 0x84) = sVar3;
    if (sVar3 >= 0x10) {
        func_8002D4C8(0x48a, 0);
        *(unsigned short *)(param_1 + 0x84) = 0;
    }
    if (*(unsigned short *)(param_1 + 0x34) == 0) {
        if (0xf00 < *(short *)(param_1 + 0xe)) {
            func_80184254(param_1);
        }
    } else {
        if (*(short *)(param_1 + 0xe) < 0x830) {
            func_80184238((void *)param_1);
        }
    }
    func_8018414C((short *)param_1);
}
