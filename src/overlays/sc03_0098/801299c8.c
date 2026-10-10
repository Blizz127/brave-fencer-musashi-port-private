/* sc03_0098: func_801299C8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern u8 D_801C5842;
extern u8 D_801C576A;
extern u8 D_801C5748;
extern u8 D_801C4190[];
extern u8 D_801C4191[];
extern u8 D_801C4192[];

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
            r = D_801C5842;
            g = D_801C576A;
            b = D_801C5748;
            D_801C4190[0] = r * 5 >> 3;
            D_801C4191[0] = g << 3;
            D_801C4192[0] = (s32)(b * 255) >> 4;
            D_801C4190[4] = (s32)(r * 143) >> 4;
            D_801C4191[4] = g * 25 >> 1;
            D_801C4192[4] = (s32)(b * 255) >> 4;
            D_801C4190[8] = (s32)(r * 255) >> 4;
            D_801C4191[8] = (s32)(g * 255) >> 4;
            D_801C4192[8] = (s32)(b * 255) >> 4;
            D_801C4190[12] = (s32)(r * 143) >> 4;
            D_801C4191[12] = (s32)(g * 255) >> 4;
            D_801C4192[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_801C4190[i] = arg2[0x44] * D_801C5842 >> 4;
            D_801C4191[i] = arg2[0x45] * D_801C576A >> 4;
            D_801C4192[i] = arg2[0x46] * D_801C5748 >> 4;
            i = (arg1 + 1) * 4;
            D_801C4190[i] = arg2[0x47] * D_801C5842 >> 4;
            D_801C4191[i] = arg2[0x48] * D_801C576A >> 4;
            D_801C4192[i] = arg2[0x49] * D_801C5748 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_801C5842 << 3;
            arg2[0x21] = D_801C576A << 3;
            arg2[0x22] = D_801C5748 << 3;
            break;
        }
    }
}
