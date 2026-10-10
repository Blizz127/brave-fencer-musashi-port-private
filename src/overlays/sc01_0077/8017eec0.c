/* sc01_0077: func_8017EEC0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 func_8017EC7C(s32 a0);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012A568(void (*a0)(void));
extern int func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
s32 func_8017EC7C(s32 param_1);
s32 func_8005C49C();
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8017EC7C(s32 a0);
extern u8 D_8018A7C0;

void func_8017EEC0(s32 param_1) {
    s32 iVar2 = *(s32 *)(param_1 + 0x20);
    func_8001CC3C(iVar2, (func_8005C49C() & 3) * 0xc + (s32)&D_8018A7C0, 0x3F0, 0x100);
    *(u8 *)(iVar2 + 0x27) = 0x9D;
    *(u16 *)(iVar2 + 0x1A) = 0x1000;
    *(u16 *)(iVar2 + 0x18) = 0x1000;
    func_8017EC7C(param_1);
    *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
}
