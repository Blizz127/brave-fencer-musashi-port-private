/* sc03_0098: func_80158E24 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern u16 func_801487F4(s32 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(int, int);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern u16 func_801487F4(s32 *a0);
extern void func_80146CA0(void *a0);
extern u16 func_801487F4(s32 *a0);
extern void func_80146CA0(void *a0);
extern u16 func_801487F4(s32 *a0);
extern s32 func_80159434(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern u16 func_801487F4(s32 *a0);
extern s32 func_80159434(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern M2C_UNK D_800D5904;
s32 func_80159434(s32 a0, s32 a1);

void func_80158E24(s32 *a0) {
    s32 n;
    s32 c;
    c = 0x4C000;
    n = 1;
    if (func_801487F4(a0) & 0xF0) {
        n = 4;
    }
    while (n > 0) {
        func_80159434((s32)a0, c);
        if (*(s16 *)(a0[0x20 / 4] + 0x10) < 0xC00) {
            *(s16 *)(a0[0x20 / 4] + 0x10) = 0xC00;
            func_80154274(a0, (s32)&D_800D5904);
            func_80154A74((s32)a0, 0x20);
            func_8002D4C8(0x2A, 0);
            func_8002D4C8(0x1C, 0);
            func_80146CA0(a0);
            n = 0;
        }
        n--;
    }
}
