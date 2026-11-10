/* sc02_0037: func_8012D664 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern u16 D_80126B66;
extern u16 D_80126B5E;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 func_800132BC(s32 a0, s32 a1);
void func_8012F568(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6);

int func_8012D664(int arg0, int arg1, int arg2)
{
    extern u16 D_80126B5E;
    extern u16 D_80126B62;
    extern u16 D_80126B66;
    extern s32 func_800132BC(s32 a0, s32 a1);
    extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
    extern u8 D_80183F48[];
    u16 s[3];
    int ret;
    int t;
    s[0] = (*(unsigned short *)&D_80126B5E);
    s[1] = (*(unsigned short *)&D_80126B62) - 0x40;
    s[2] = (*(unsigned short *)&D_80126B66);
    ret = ((int (*)())func_800132BC)(arg0, s);
    t = arg1 + 0x20;
    if (ret < t * t) {
        func_8012F568(1, 1, 0, arg2, arg0, &D_80183F48);
        return 1;
    }
    return 0;
}
