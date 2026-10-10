/* sc01_0077: func_8014462C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern void func_80016714(void *a0, s32 a1);
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
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_80016714(void *a0, s32 a1);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012AD80(s32 a0);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);

void func_8014462C(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0xCC);
    func_8012AD80((s32)a0);
    *(u16 *)(s1 + 8) = *(u16 *)(a0 + 6);
    *(u16 *)(s1 + 0xA) = *(u16 *)(a0 + 0xA);
    *(u16 *)(s1 + 0xC) = *(u16 *)(a0 + 0xE);
    if (func_80128ED8(s1, a0 + 0xD0)) {
        func_80016714(s1, 0x38);
        func_8012C218(a0);
    }
}
