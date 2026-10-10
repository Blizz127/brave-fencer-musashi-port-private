/* sc01_0077: func_8017F290 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 D_80078EC1;
extern u16 D_80126B66;
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8016EDEC(s32 _arg0, s32 _arg1, s32 _arg2);
extern void func_8012A568(void (*a0)(void));
extern u16 D_80126B66;
extern u16 D_80126B66;
extern u16 D_80126B66;
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
void func_8017E1D4(void *arg0);
extern u8 D_80078EC1;
void func_8017E748(void *arg0);
void func_8017E868(void *arg0);
extern s32 D_801270D4;
extern u16 D_80126B66;
extern int D_801270CC;
extern int D_801270D4;
extern u16 D_80126B66;
extern unsigned char D_80078EC1;
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8017E1D4(void *arg0);
extern void func_8017E748(void *arg0);
extern void func_8017E868(void *arg0);

void func_8017F290(void)
{
    int *state = &D_801270CC;
    switch (*state) {
    case 0:
        if ((*(short *)&D_80126B66) < 0x600) {
            return;
        }
        if ((D_80078EC1 & 0x7F) == 8) {
            ((void (*)(void *, int))func_8016EDEC)(func_8017E1D4, 0x1000000);
            *state = 2;
        } else {
            ((void (*)(void *, int))func_8016EDEC)(func_8017E1D4, 0x1000000);
            *state = 1;
            return;
        }
        break;
    case 1:
        if ((D_80078EC1 & 0x7F) != 8) {
            return;
        }
        ((void (*)(void *, int))func_8016EDEC)(func_8017E748, 0x1000000);
        *state = 2;
        break;
    case 2:
        if (D_801270D4 == 0) {
            return;
        }
        *state = 3;
        D_801270D4 = D_801270D4 + 1;
        ((void (*)(void *, int))func_8016EDEC)(func_8017E868, 0x1000000);
        break;
    case 3:
        if (D_801270D4 == 0) {
            return;
        }
        D_801270D4 = D_801270D4 + 1;
        break;
    }
}
