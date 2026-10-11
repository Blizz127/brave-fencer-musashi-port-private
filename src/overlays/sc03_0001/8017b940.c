/* sc03_0001: func_8017B940 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s16 D_801EE5DC;
extern u16 D_801EE65C;
extern u16 D_801EE65E;
extern u16 D_801EE660;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801EE5DC;
extern s16 D_801EE654;
extern s16 D_801EE656;
extern s16 D_801EE658;
extern s16 D_801EE64C;
extern s16 D_801EE64E;
extern s16 D_801EE650;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u16 D_801EE65C;
extern u16 D_801EE65E;
extern u16 D_801EE660;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801EE5DC;
extern short D_801EE664;
extern short D_801EE666;
extern short D_801EE668;
extern s16 D_801EE654;
extern s16 D_801EE656;
extern s16 D_801EE658;
extern s16 D_801EE64C;
extern s16 D_801EE64E;
extern s16 D_801EE650;

void func_8017B940(void)
{
    extern u16 D_80126B5E;
    extern u16 D_80126B66;
    extern u16 D_80126B62;
    s32 buf[3];
    D_8012694C = 2;
    buf[0] = (*(s16 *)&D_80126B5E) - (*(s16 *)&D_801EE65C);
    buf[1] = (*(s16 *)&D_80126B62) - (*(s16 *)&D_801EE65E);
    buf[2] = (*(s16 *)&D_80126B66) - (*(s16 *)&D_801EE660);
    (*(s16 *)&D_801EE664) = buf[0];
    (*(s16 *)&D_801EE666) = buf[1];
    (*(s16 *)&D_801EE668) = buf[2];
    D_801EE654 = D_80114F30 + buf[0];
    D_801EE5DC = 0;
    D_801EE656 = D_80114F34 + buf[1];
    D_801EE658 = D_80114F38 + buf[2];
    D_801EE64C = D_80114F24 + buf[0];
    D_801EE64E = D_80114F28 + buf[1];
    D_801EE650 = D_80114F2C + buf[2];
}
