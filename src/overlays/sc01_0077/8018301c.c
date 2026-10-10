/* sc01_0077: func_8018301C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182E7C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern unsigned char D_801B09D0;
extern void func_8012A828(int a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32, void *);
extern void func_8002D4C8(s32, s32);
extern unsigned char D_801B09D0;

void func_8018301C(s32 param_1)
{
    *(s16 *)(param_1 + 2) = 0x10;
    *(s16 *)(param_1 + 0x34) = 0;
    *(s16 *)(param_1 + 0x5c) = 0;
    *(s32 *)(param_1 + 0x1c) = 0;
    ((void (*)(s32, u8 *))func_8012A828)(param_1, ((u8 *)&D_801B09D0));
    *(s16 *)(param_1 + 0x98) = 0;
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x2c) |= 0x10;
    *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x1a) = 0x100;
    func_8002D4C8(0x436, 0);
}
