/* sc01_0077: func_8018281C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182268.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern s32 D_801270D4;
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012B2CC(int);
extern void func_8012B23C(int);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern s32 func_8012CBA4(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B23C(s32 a0);
extern s32 func_8012CBA4(s32);
extern int func_8012BEE8(int a0);
extern void func_8012B2CC(int a0);
extern void func_8012B23C(int a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012A828(int a0, void *a1);
extern void func_80182968(void);
extern int func_8005C49C(void);
extern int D_801270D4;
extern unsigned char D_8018AA8C[];
extern unsigned char D_801AFF18[];
void func_80182968(void);

void func_8018281C(int param_1)
{
    int iVar1;
    unsigned int uVar2;
    ((void (*)(void))func_8012CBA4)();
    if ((((int)((unsigned int)*(unsigned short *)(param_1 + 0x70) << 0x10) >> 0x18 != 4) ||
         (D_801270D4 == 0)) &&
        (iVar1 = func_8012BEE8(param_1), iVar1 != 0)) {
        *(char *)(param_1 + 0xc1) = 0;
        *(short *)(param_1 + 2) = 1;
        *(short *)(param_1 + 0x34) = 0;
        uVar2 = func_8005C49C();
        *(int *)(param_1 + 0x1c) = (uVar2 & 0x1f) + 0x46;
        *(short *)(param_1 + 0xe0) = 0;
        *(short *)(param_1 + 0xe2) = *(short *)(*(int *)(param_1 + 0x20) + 0x12);
        switch ((int)((unsigned int)*(unsigned short *)(param_1 + 0x70) << 0x10) >> 0x18) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 7:
            if ((*(unsigned short *)(param_1 + 0xfe) & 2) != 0) {
                *(short *)(param_1 + 0xe2) = 0;
            }
            goto do_default;
        case 5:
            ((void (*)(int))func_80182968)(param_1);
            break;
        case 4:
        case 6:
        default:
        do_default:
            *(short *)(param_1 + 0xe4) = 0x1e;
            *(short *)(param_1 + 0x5e) = 0;
            *(unsigned short *)(param_1 + 0x5c) = 0xaa10;
            func_8012B2CC(param_1);
            func_8012B23C(param_1);
            ((void (*)(int, void *))func_8012B14C)(param_1, &D_8018AA8C);
            func_8012A828(param_1, &D_801AFF18);
            break;
        }
    }
}
