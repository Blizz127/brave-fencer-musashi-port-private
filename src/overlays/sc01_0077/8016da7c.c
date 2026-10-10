/* sc01_0077: func_8016DA7C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_801465C0(void);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_801465C0(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_80146C3C(void);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern u8 D_80189DBC;
extern u8 D_80189DC8;

void func_8016DA7C(s32 param_1)
{
    s32 iVar1;
    iVar1 = ((s32 (*)(void))func_801465C0)();
    if (iVar1 == 0) {
        ((void (*)(s32))func_80146C3C)(param_1);
    } else {
        *(s32 *)(param_1 + 0x20) = iVar1;
        ((void (*)(s32, s32, s32, s32))func_8001CC3C)(iVar1, (s32)&D_80189DBC, 0x250, 0x100);
        *(u8 *)(iVar1 + 0x27) = 0x90;
        *(u16 *)(iVar1 + 0x18) = 0x3000;
        *(u16 *)(iVar1 + 0x1a) = 0x4000;
        *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        func_80128EA8(iVar1, param_1 + 0x24, (s32)&D_80189DC8);
        *(s32 *)(param_1 + 0x10) = 0;
        *(s32 *)(param_1 + 0x14) = 0xfff40000;
        *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
    }
}
