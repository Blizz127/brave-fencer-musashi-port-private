/* sc03_0098: func_8016EBA8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8016EC0C(s32 a0, s32 a1);
extern u16 D_801886E0[];
extern void func_8016EC0C(s32 a0, s32 a1);
extern void func_8016EC0C(s32 a0, s32 a1);
extern u16 D_801886E0[];
extern void func_8016EC0C(s32 a0, s32 a1);
void func_8016EC0C(s32 a0, s32 a1);

void func_8016EBA8(u8 *param_1)
{
    u8 c;
    *(u16 *)(param_1 + 4) =
        *(u16 *)(param_1 + 4) - D_801886E0[param_1[2]];
    ((void (*)(u8 *, int))func_8016EC0C)(param_1, 0x80);
    c = param_1[2];
    param_1[2] = c + 0xFF;
    if (c == 0) {
        param_1[0] = 0;
    }
}
