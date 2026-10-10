/* sc01_0077: func_801437D8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
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
extern u8 *func_8012913C(s32 a0);
extern s32 func_8005C49C(void);
extern u8 *func_8012913C(s32 a0);
extern s32 func_8005C49C(void);

void func_801437D8(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *s0;
    s32 r;
    s32 d0, d1, d2;
    s32 t;
    s32 pad[6];
    (void)pad;
    if ((*(u16 *)(a0 + 0) & (s16)((1 << a3) - 1)) == 0) {
        s0 = func_8012913C(0x23);
        if (s0 != 0) {
            r = func_8005C49C();
            d0 = *(s16 *)(a2 + 0);
            *(s16 *)(s0 + 6) = (*(u16 *)(a1 + 0) + (r % (d0 << 1))) - d0;
            r = func_8005C49C();
            d1 = *(s16 *)(a2 + 2);
            *(s16 *)(s0 + 0xA) = (*(u16 *)(a1 + 2) + (r % (d1 << 1))) - d1;
            r = func_8005C49C();
            d2 = *(s16 *)(a2 + 4);
            t = *(u16 *)(a1 + 4);
            *(s32 *)(s0 + 0x18) = 0;
            *(s32 *)(s0 + 0x14) = 0;
            *(s32 *)(s0 + 0x10) = 0;
            *(s16 *)(s0 + 0xE) = (t + (r % (d2 << 1))) - d2;
            *(s16 *)(s0 + 0x34) = *(u16 *)(a1 + 6);
            *(u16 *)(*(s32 *)(s0 + 0x20) + 0x2C) = 0xC008;
        }
    }
    *(u16 *)(a0 + 0) += 1;
}
