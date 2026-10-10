/* sc01_0077: func_80180B64 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80180B64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern int func_8005C49C(void);
extern void func_8012B2CC();
extern void func_8012B23C();
extern void func_8012B14C();
extern void func_8012A828();
extern void func_80182968();
extern u8 D_8018AA8C[];
extern u8 D_801AFF18[];

void func_80180B64(int param_1)
{
    *(u8 *)(param_1 + 0xc1) = 0;
    *(s16 *)(param_1 + 2) = 1;
    *(s16 *)(param_1 + 0x34) = 0;
    *(s32 *)(param_1 + 0x1c) = (func_8005C49C() & 0x1f) + 0x46;
    *(s16 *)(param_1 + 0xe0) = 0;
    *(u16 *)(param_1 + 0xe2) = *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x12);
    switch ((s32)((u32)*(u16 *)(param_1 + 0x70) << 0x10) >> 0x18) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 7:
        if (*(u16 *)(param_1 + 0xfe) & 2) {
            *(s16 *)(param_1 + 0xe2) = 0;
        }
        goto L_default;
    case 5:
        func_80182968(param_1);
        break;
    case 4:
    case 6:
    default:
    L_default:
        *(s16 *)(param_1 + 0xe4) = 0x1e;
        *(s16 *)(param_1 + 0x5e) = 0;
        *(u16 *)(param_1 + 0x5c) = 0xaa10;
        func_8012B2CC(param_1);
        func_8012B23C(param_1);
        func_8012B14C(param_1, D_8018AA8C);
        func_8012A828(param_1, D_801AFF18);
        break;
    }
    *(s16 *)(param_1 + 0x34) = 3;
    {
        u16 tmp = *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x12);
        *(s16 *)(param_1 + 0xe0) = 0;
        *(u16 *)(param_1 + 0xe2) = (tmp + 0x800) & 0xfff;
    }
    *(u16 *)(param_1 + 0xe4) = (func_8005C49C() & 0x1f) + 0x1e;
    *(s32 *)(param_1 + 0x1c) = 0x16;
}
