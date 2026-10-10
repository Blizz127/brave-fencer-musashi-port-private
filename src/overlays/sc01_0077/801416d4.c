/* sc01_0077: func_801416D4 from Druthulu/BFM-decomp
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
extern s16 D_8011514C;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern void func_80141C0C(s32);
extern s16 D_8011514C;
extern u8 D_8011515C;
extern void func_80141C0C(s32 a0);
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern s16 D_8011514C;
extern u8 D_8011514D;
extern u8 D_8011515C;
extern s32 func_800D11F0(s32 a0);
extern s32 func_800D1658(s32 a0);
extern void func_80141C0C(s32);
void func_80141C0C(s32 param_1);

s32 func_801416D4(s16 param_1) {
    s32 cVar2;
    register s32 iVar1 __asm__("$3");
    s32 two;
    two = 2;
    iVar1 = 0;
    cVar2 = *(u8 *)&D_8011514C + D_8011514D * D_8011515C;
    if (param_1 == 1) goto c1;
    if (param_1 < 2) {
        if (param_1 == 0) goto c0;
        goto ret;
    }
    if (param_1 == two) goto c2;
    goto ret;
c0:
    iVar1 = func_800D11F0(cVar2 & 0xFF);
    goto ret;
c1:
    iVar1 = func_800D1658(cVar2 & 0xFF);
    goto ret;
c2:
    func_80141C0C(6);
    iVar1 = 1;
ret:
    return (iVar1 << 0x10) >> 0x10;
}
