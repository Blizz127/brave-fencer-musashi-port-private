/* sc02_0037: func_801299C8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern u8 D_801C9A72;
extern u8 D_801C999A;
extern u8 D_801C9978;
extern u8 D_801C83B0[];
extern u8 D_801C83B1[];
extern u8 D_801C83B2[];

void func_801299C8(arg0, arg1, arg2)
s16 arg0;
s16 arg1;
u8 *arg2;
{
    u32 r;
    u32 g;
    u32 b;
    s32 i;
    if (arg0 != 0) {
        switch (arg1) {
        case 1:
            r = D_801C9A72;
            g = D_801C999A;
            b = D_801C9978;
            D_801C83B0[0] = r * 5 >> 3;
            D_801C83B1[0] = g << 3;
            D_801C83B2[0] = (s32)(b * 255) >> 4;
            D_801C83B0[4] = (s32)(r * 143) >> 4;
            D_801C83B1[4] = g * 25 >> 1;
            D_801C83B2[4] = (s32)(b * 255) >> 4;
            D_801C83B0[8] = (s32)(r * 255) >> 4;
            D_801C83B1[8] = (s32)(g * 255) >> 4;
            D_801C83B2[8] = (s32)(b * 255) >> 4;
            D_801C83B0[12] = (s32)(r * 143) >> 4;
            D_801C83B1[12] = (s32)(g * 255) >> 4;
            D_801C83B2[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_801C83B0[i] = arg2[0x44] * D_801C9A72 >> 4;
            D_801C83B1[i] = arg2[0x45] * D_801C999A >> 4;
            D_801C83B2[i] = arg2[0x46] * D_801C9978 >> 4;
            i = (arg1 + 1) * 4;
            D_801C83B0[i] = arg2[0x47] * D_801C9A72 >> 4;
            D_801C83B1[i] = arg2[0x48] * D_801C999A >> 4;
            D_801C83B2[i] = arg2[0x49] * D_801C9978 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_801C9A72 << 3;
            arg2[0x21] = D_801C999A << 3;
            arg2[0x22] = D_801C9978 << 3;
            break;
        }
    }
}
