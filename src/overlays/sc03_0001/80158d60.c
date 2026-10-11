/* sc03_0001: func_80158D60 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern u16 func_801487F4(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 a0);
extern u16 func_801487F4(s32 *a0);
extern void func_80146CA0(void *a0);
extern u16 func_801487F4(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern u16 func_801487F4(s32 *a0);
extern s32 func_80159434(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
s32 func_80159434(s32 a0, s32 a1);

void func_80158D60(s32 a0) {
    s32 count;
    s32 i;
    s32 arg;
    arg = 0x4C000;
    count = 1;
    if (func_801487F4((s32 *)a0) & 0xF0) {
        count = 4;
    }
    for (i = count; i > 0; i--) {
        func_80159434(a0, arg);
        if (*(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) < 0xC00) {
            func_80147324(0x454);
            *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0xC00;
            *(s32 *)(a0 + 0x238) = 0xFFEA0000;
            func_80146CA0((void *)a0);
            i = 0;
        }
    }
}
