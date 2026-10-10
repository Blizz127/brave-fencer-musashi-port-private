/* sc01_0077: func_80155B20 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_80146CA0(void *a0);
extern void func_80146D80(s32 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern int func_80161208();
extern void func_80146D80(s32 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern u8 D_800D4DA8[];

void func_80155B20(s32 *a0) {
    a0[0x44 / 4] |= 2;
    if (func_80161208() == 0) {
        if (*(u16 *)((char *)a0 + 0xB8) == 0x8000) {
            func_80146D80(a0);
            func_801477E8(a0, 0xFFF00000);
            func_80154274(a0, (s32)D_800D4DA8);
            func_80146CA0(a0);
        }
    }
}
