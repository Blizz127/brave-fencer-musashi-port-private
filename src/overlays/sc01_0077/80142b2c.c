/* sc01_0077: func_80142B2C from Druthulu/BFM-decomp
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
extern s32 func_8012AD50(void *a0);
extern s32 func_8012AD50(void *a0);
extern s32 func_8012AD50(void *a0);
void func_80142C84(s32 a0);
void func_80143994(s32 a0, s32 a1);
extern void func_80142C84(s32 a0);
extern void func_80143994(s32 a0, s32 a1);
extern s32 func_8012AD50(void *a0);
void func_80142C84(s32 a0);
void func_80143994(s32 a0, s32 a1);

void func_80142B2C(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x1c) = 0x180;
    *(s16 *)((u8 *)arg0 + 0x5c) = 0x100;
    *(u16 *)((u8 *)arg0 + 0x100) = *(u16 *)((u8 *)arg0 + 0x70) & 0x100;
    *(u16 *)((u8 *)arg0 + 0x70) = *(u16 *)((u8 *)arg0 + 0x70) & 3;
    *(u16 *)((u8 *)arg0 + 0x72) = *(u16 *)((u8 *)arg0 + 0x72) | 0x1000;
    if (*(s16 *)((u8 *)arg0 + 0x100) == 0) {
        ((void (*)(void))func_80142C84)();
    }
    *(s32 *)((u8 *)arg0 + 0xcc) =
        ((s32 (*)(s32, s32))func_80143994)(
            (s32)arg0, (s32)*(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x18));
    func_8012AD50(arg0);
}
