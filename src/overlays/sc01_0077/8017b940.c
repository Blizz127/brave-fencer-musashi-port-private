/* sc01_0077: func_8017B940 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_801DA71C;
extern u16 D_801DA79C;
extern u16 D_801DA79E;
extern u16 D_801DA7A0;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801DA71C;
extern s16 D_801DA794;
extern s16 D_801DA796;
extern s16 D_801DA798;
extern s16 D_801DA78C;
extern s16 D_801DA78E;
extern s16 D_801DA790;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern u16 D_801DA79C;
extern u16 D_801DA79E;
extern u16 D_801DA7A0;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801DA71C;
extern short D_801DA7A4;
extern short D_801DA7A6;
extern short D_801DA7A8;
extern s16 D_801DA794;
extern s16 D_801DA796;
extern s16 D_801DA798;
extern s16 D_801DA78C;
extern s16 D_801DA78E;
extern s16 D_801DA790;

void func_8017B940(void)
{
    s32 buf[3];
    D_8012694C = 2;
    buf[0] = (*(s16 *)&D_80126B5E) - (*(s16 *)&D_801DA79C);
    buf[1] = (*(s16 *)&D_80126B62) - (*(s16 *)&D_801DA79E);
    buf[2] = (*(s16 *)&D_80126B66) - (*(s16 *)&D_801DA7A0);
    (*(s16 *)&D_801DA7A4) = buf[0];
    (*(s16 *)&D_801DA7A6) = buf[1];
    (*(s16 *)&D_801DA7A8) = buf[2];
    D_801DA794 = D_80114F30 + buf[0];
    D_801DA71C = 0;
    D_801DA796 = D_80114F34 + buf[1];
    D_801DA798 = D_80114F38 + buf[2];
    D_801DA78C = D_80114F24 + buf[0];
    D_801DA78E = D_80114F28 + buf[1];
    D_801DA790 = D_80114F2C + buf[2];
}
