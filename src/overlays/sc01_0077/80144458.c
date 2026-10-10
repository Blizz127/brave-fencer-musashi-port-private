/* sc01_0077: func_80144458 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
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
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern void func_80016714(void *a0, s32 a1);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern s32 D_80188448;

void func_80144458(void *arg0) {
    s32 temp_s0;
    void *temp_s2;
    void *temp_v0;
    temp_s2 = (*(void **)((s8 *)(arg0) + (0xCC)));
    if ((*(s16 *)((s8 *)(arg0) + (0x70))) == 0) {
        temp_v0 = (*(void **)((s8 *)((*(void **)((s8 *)(arg0) + (0x64)))) + (0x20)));
        if (temp_v0 != ((void *)0)) {
            temp_s0 = ((*(s16 *)((s8 *)(temp_v0) + (0x12))) - 0x400) & 0xFFF;
            (*(s32 *)((s8 *)(arg0) + (0x10))) = (s32) (func_80047948(temp_s0) * D_80188448 * 0x10);
            (*(s32 *)((s8 *)(arg0) + (0x18))) = (s32) (func_8004787C(temp_s0) * -D_80188448 * 0x10);
            func_8012AD80(arg0);
        }
    }
    (*(u16 *)((s8 *)(temp_s2) + (8))) = (u16) (*(u16 *)((s8 *)(arg0) + (6)));
    (*(u16 *)((s8 *)(temp_s2) + (0xA))) = (u16) (*(u16 *)((s8 *)(arg0) + (0xA)));
    (*(u16 *)((s8 *)(temp_s2) + (0xC))) = (u16) (*(u16 *)((s8 *)(arg0) + (0xE)));
    if (func_80128ED8(temp_s2, arg0 + 0xD0) != 0) {
        func_80016714(temp_s2, 0x38);
        func_8012C218(arg0);
    }
}
