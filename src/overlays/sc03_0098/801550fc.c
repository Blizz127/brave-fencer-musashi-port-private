/* sc03_0098: func_801550FC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
typedef struct {
    u8 b[8];
} ImgRect8;
extern void func_80059A80(void *a0, s32 a1, s32 a2);
extern void func_80059A80(void *a0, s32 a1, s32 a2);
extern void func_800183E0(s32 a0);
extern ImgRect8 D_8018714C[];

void func_801550FC(s32 arg0)
{
    if (arg0 & 0x40000000) {
        func_80059A80(&D_8018714C[arg0 & 0xFF], 0x200, 0x100);
    } else {
        ((void (*)(void))func_800183E0)();
    }
}
