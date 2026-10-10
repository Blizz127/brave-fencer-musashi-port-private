/* sc01_0077: func_801754A8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef int (*DispatchFn)();
extern s32 func_80029504(void);
extern s32 D_80126B9C;
extern s32 D_80126B9C;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern s32 func_80029504(void);
extern u8 D_8011F7A8;
extern unsigned char D_800B9A13;
extern s32 D_80126B9C;
extern DispatchFn D_8018A308[];

void func_801754A8(void) {
    u8 *p = &D_8011F7A8;
    s32 r = func_80029504();
    s32 flag = 0;
    if (((D_800B9A13 == 0) && ((D_80126B9C & 0x80) == 0)) ||
        (0x4AF < (u32)(r - 10))) {
        flag = 1;
    }
    p[9] = flag;
    D_8018A308[p[0]]((void *)p);
}
