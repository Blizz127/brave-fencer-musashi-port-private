/* sc01_0077: func_801299C8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_a.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern u8 D_801DAABA;
extern u8 D_801DA9C2;
extern u8 D_801DA998;
extern u8 D_801D9488[];
extern u8 D_801D9489[];
extern u8 D_801D948A[];

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
            r = D_801DAABA;
            g = D_801DA9C2;
            b = D_801DA998;
            D_801D9488[0] = r * 5 >> 3;
            D_801D9489[0] = g << 3;
            D_801D948A[0] = (s32)(b * 255) >> 4;
            D_801D9488[4] = (s32)(r * 143) >> 4;
            D_801D9489[4] = g * 25 >> 1;
            D_801D948A[4] = (s32)(b * 255) >> 4;
            D_801D9488[8] = (s32)(r * 255) >> 4;
            D_801D9489[8] = (s32)(g * 255) >> 4;
            D_801D948A[8] = (s32)(b * 255) >> 4;
            D_801D9488[12] = (s32)(r * 143) >> 4;
            D_801D9489[12] = (s32)(g * 255) >> 4;
            D_801D948A[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_801D9488[i] = arg2[0x44] * D_801DAABA >> 4;
            D_801D9489[i] = arg2[0x45] * D_801DA9C2 >> 4;
            D_801D948A[i] = arg2[0x46] * D_801DA998 >> 4;
            i = (arg1 + 1) * 4;
            D_801D9488[i] = arg2[0x47] * D_801DAABA >> 4;
            D_801D9489[i] = arg2[0x48] * D_801DA9C2 >> 4;
            D_801D948A[i] = arg2[0x49] * D_801DA998 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_801DAABA << 3;
            arg2[0x21] = D_801DA9C2 << 3;
            arg2[0x22] = D_801DA998 << 3;
            break;
        }
    }
}
