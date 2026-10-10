/* sc01_0077: func_80142454 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
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
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 func_8012C51C(void *a0, s32 a1);

void func_80142454(s32 a0) {
    s32 s0 = a0;
    u16 *s1 = &D_80126B5E;
    s32 ret;
    s16 st[10];
    st[3] = 0x13;
    st[0] = *s1;
    st[1] = D_80126B62;
    st[2] = D_80126B66;
    st[4] = 1;
    st[5] = 0;
    st[7] = 0;
    *(s32 *)&st[8] = 0;
    ret = ((s32 (*)(void *, s32))func_8012C51C)(st, 0);
    if (ret != 0) {
        *(s16 *)(ret + 0x52) = s0;
        *(s32 *)(ret + 0x64) = (s32)s1 - 6;
    }
}
