/* sc01_0077: func_8017E8A4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
extern void func_80171B44(s32 *a0);
extern s32 func_80172658(s32 *a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80171B44(s32 *a0);
extern void func_80171B44(s32 *a0);
extern s32 D_801270D4;
extern s32 func_80172658(s32 *a0);
extern void func_80171B44(s32 *a0);

void func_8017E8A4(u16 *param_1)
{
    s32 cVar1;
    if (1 < (u16)(*param_1 - 0x19)) {
        if (D_801270D4 < 0x1e) {
            __asm__ __volatile__("" ::: "$4");
            if (((s32 (*)(u16 *))func_80172658)(param_1) == 0) {
                return;
            }
            *(u16 *)(*(s32 *)(param_1 + 0x10) + 0x12) = 0;
            ((void (*)(u16 *))func_80171B44)(param_1);
            cVar1 = *(u8 *)(param_1 + 0x10a) + 1;
        } else {
            cVar1 = 4;
        }
        *(s8 *)(param_1 + 0x10a) = cVar1;
    }
}
