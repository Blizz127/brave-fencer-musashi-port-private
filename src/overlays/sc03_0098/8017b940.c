/* sc03_0098: func_8017B940 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern u16 D_80126B5E;
extern u16 D_80126B66;
extern u16 D_80126B5E;
extern u16 D_80126B66;
extern s16 D_801C5424;
extern u16 D_801C54A4;
extern u16 D_801C54A6;
extern u16 D_801C54A8;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801C5424;
extern s16 D_801C549C;
extern s16 D_801C549E;
extern s16 D_801C54A0;
extern s16 D_801C5494;
extern s16 D_801C5496;
extern s16 D_801C5498;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u16 D_80126B5E;
extern u16 D_80126B66;
extern u16 D_801C54A4;
extern u16 D_801C54A6;
extern u16 D_801C54A8;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801C5424;
extern short D_801C54AC;
extern short D_801C54AE;
extern short D_801C54B0;
extern s16 D_801C549C;
extern s16 D_801C549E;
extern s16 D_801C54A0;
extern s16 D_801C5494;
extern s16 D_801C5496;
extern s16 D_801C5498;

void func_8017B940(void)
{
    extern u16 D_80126B62;
    s32 buf[3];
    D_8012694C = 2;
    buf[0] = (*(s16 *)&D_80126B5E) - (*(s16 *)&D_801C54A4);
    buf[1] = (*(s16 *)&D_80126B62) - (*(s16 *)&D_801C54A6);
    buf[2] = (*(s16 *)&D_80126B66) - (*(s16 *)&D_801C54A8);
    (*(s16 *)&D_801C54AC) = buf[0];
    (*(s16 *)&D_801C54AE) = buf[1];
    (*(s16 *)&D_801C54B0) = buf[2];
    D_801C549C = D_80114F30 + buf[0];
    D_801C5424 = 0;
    D_801C549E = D_80114F34 + buf[1];
    D_801C54A0 = D_80114F38 + buf[2];
    D_801C5494 = D_80114F24 + buf[0];
    D_801C5496 = D_80114F28 + buf[1];
    D_801C5498 = D_80114F2C + buf[2];
}
