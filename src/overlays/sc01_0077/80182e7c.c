/* sc01_0077: func_80182E7C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182E7C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012B2CC(int);
extern void func_8012B23C(int);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012B23C(s32 a0);
extern int func_8012BEE8(int a0);
extern void func_8012B2CC(int a0);
extern void func_8012B23C(int a0);
extern void func_8012A828(int a0, void *a1);
extern void func_80182968(void);
extern unsigned char D_8018AA8C[];
extern unsigned char D_801AFF18[];
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012BEE8(s32);
extern void func_8012B2CC(s32);
extern void func_8012B23C(s32);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_80182968(void);
extern s32 func_8005C49C(void);
extern u8 D_801AFD28;
extern unsigned char D_8018AA8C[];
extern unsigned char D_801AFF18[];

void func_80182E7C(s32 param_1)
{
    switch (*(u16 *)(param_1 + 0x34)) {
    case 0:
        if ((*(u16 *)(param_1 + 0x72) & 0x4000) != 0) {
            *(u16 *)(param_1 + 0x34) = 1;
            ((s32 (*)(s32, void *))func_8012A828)(param_1, &D_801AFD28);
            *(s32 *)(param_1 + 0x1c) = 10;
        }
        break;
    case 1:
        if (func_8012BEE8(param_1) != 0) {
            *(u8 *)(param_1 + 0xc1) = 0;
            *(u16 *)(param_1 + 0x2) = 1;
            *(u16 *)(param_1 + 0x34) = 0;
            *(s32 *)(param_1 + 0x1c) = (func_8005C49C() & 0x1f) + 0x46;
            *(u16 *)(param_1 + 0xe0) = 0;
            *(u16 *)(param_1 + 0xe2) = *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x12);
            switch ((s32)((u32)*(u16 *)(param_1 + 0x70) << 0x10) >> 0x18) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 7:
                if ((*(u16 *)(param_1 + 0xfe) & 2) != 0) {
                    *(u16 *)(param_1 + 0xe2) = 0;
                }
                goto seq;
            case 5:
                ((void (*)(s32))func_80182968)(param_1);
                break;
            case 4:
            case 6:
            default:
            seq:
                *(u16 *)(param_1 + 0xe4) = 0x1e;
                *(u16 *)(param_1 + 0x5e) = 0;
                *(u16 *)(param_1 + 0x5c) = 0xaa10;
                func_8012B2CC(param_1);
                func_8012B23C(param_1);
                ((void (*)(s32, void *))func_8012B14C)(param_1, &(*(u8 *)D_8018AA8C));
                ((s32 (*)(s32, void *))func_8012A828)(param_1, &(*(u8 *)D_801AFF18));
                break;
            }
        }
        break;
    }
}
