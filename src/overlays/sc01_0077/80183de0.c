/* sc01_0077: func_80183DE0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct { u8 b[8]; } Blk8;
extern u16 D_80126B66;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C51C(void *a0, s32 a1);
void func_80183F4C(int param_1);

void func_80183DE0(int param)
{
    extern u16 D_80126B66;
    extern unsigned char D_8018AE0C;
    extern unsigned char D_8018AE34;
    extern s32 func_8012C51C(void *a0, s32 a1);
    extern void func_80183F4C();
    int i;
    unsigned char *puVar8;
    int iVar7;
    int src;
    short sVar1;
    iVar7 = *(int *)(param + 0xcc);
    if (iVar7 != 0) {
        *(short *)(iVar7 + 0x18) = 0x1800;
        *(unsigned short *)(iVar7 + 0x2c) |= 0x10;
        src = *(int *)(param + 0x20);
        *(Blk8 *)(iVar7 + 8) = *(Blk8 *)(src + 8);
        *(unsigned short *)(iVar7 + 0xa) -= 0x10;
        *(unsigned short *)(iVar7 + 0x10) =
            *(unsigned short *)(iVar7 + 0x10) + *(short *)(param + 0x1a) * -0x10;
    }
    sVar1 = *(short *)(param + 0xfe);
    if (sVar1 != 1) {
        if (sVar1 < 2 && sVar1 == 0 && (*(short *)&D_80126B66) >= 0x6e0) {
            *(short *)(param + 0xfe) = 1;
            i = 0;
            puVar8 = (unsigned char *)&D_8018AE0C;
            do {
                func_8012C51C(puVar8, 0);
                i = i + 1;
                puVar8 = puVar8 + 0x14;
            } while (i < 2);
        }
    } else {
        if ((*(short *)&D_80126B66) >= 0x900) {
            *(short *)(param + 0xfe) = 2;
            i = 2;
            puVar8 = (unsigned char *)&D_8018AE34;
            do {
                func_8012C51C(puVar8, 0);
                i = i + 1;
                puVar8 = puVar8 + 0x14;
            } while (i < 5);
        }
    }
    if (*(short *)(param + 0xfc) != *(short *)(param + 0xe)) {
        func_80183F4C(param);
    }
}
