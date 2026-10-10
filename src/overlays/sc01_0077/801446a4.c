/* sc01_0077: func_801446A4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern u16 D_80115116;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern short D_800B9A02;
extern u16 D_80115116;
extern short D_800B9A02;
extern u16 D_80115116;
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern u8 D_800D387C[];
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_8012C194(void);
extern void func_8012CAE4(void *a0);
extern void func_8012C194(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern u8 D_800D387C[];
extern u8 D_800D3888[];
extern void func_8012C194(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern u8 D_800D3888[];
extern u8 D_800D387C[];

void func_801446A4(int param_1)
{
    register int s1 __asm__("$17");
    int iVar1;
    s1 = param_1;
    iVar1 = ((int (*)(void))func_8012C194)();
    if (iVar1 == 0) {
        ((void (*)(int))func_8012CAE4)(s1);
    } else {
        *(int *)(s1 + 0xcc) = iVar1;
        ((void (*)(int, int, int, int))func_8001CC3C)(iVar1, 0, 0, 0);
        *(int *)(iVar1 + 0x20) = (int)&D_800D387C;
        *(unsigned char *)(iVar1 + 0x27) = 0x9c;
        *(short *)(iVar1 + 0x1a) = 0x3000;
        *(short *)(iVar1 + 0x18) = 0x3000;
        *(unsigned int *)(iVar1 + 4) = *(unsigned int *)(iVar1 + 4) | 0x50000000;
        func_80128EA8(iVar1, s1 + 0xd0, (int)&D_800D3888);
        *(short *)(iVar1 + 8) = *(unsigned short *)(s1 + 6);
        *(short *)(iVar1 + 0xa) = *(unsigned short *)(s1 + 0xa);
        *(short *)(iVar1 + 0xc) = *(unsigned short *)(s1 + 0xe);
        *(short *)(s1 + 2) = *(short *)(s1 + 2) + 1;
    }
}
