/* sc01_0077: func_80158C40 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern u16 func_801487F4(s32 *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern u16 func_801487F4(s32 *a0);
extern s32 func_80159404(s32 a0, s32 a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
s32 func_80159404(s32 a0, s32 a1);

void func_80158C40(s32 *a0) {
    s32 n;
    s32 c;
    c = 0x3C000;
    n = 1;
    if (func_801487F4(a0) & 0xF0) {
        n = 4;
    }
    while (n > 0) {
        func_80159404((s32)a0, c);
        if (a0[0x234 / 4] < 0) {
            func_80146E90(a0, 4);
            func_80146CA0(a0);
            n = 0;
        }
        n--;
    }
}
