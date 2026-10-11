/* sc03_0001: func_801754A8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef int (*DispatchFn)();
extern s32 func_80029504(void);
extern s32 D_80126B9C;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern s32 func_80029504(void);

void func_801754A8(void) {
    extern u8 D_8011F7A8;
    extern unsigned char D_800B9A13;
    extern s32 D_80126B9C;
    extern DispatchFn D_80190CF8[];
    u8 *p = &D_8011F7A8;
    s32 r = func_80029504();
    s32 flag = 0;
    if (((D_800B9A13 == 0) && ((D_80126B9C & 0x80) == 0)) ||
        (0x4AF < (u32)(r - 10))) {
        flag = 1;
    }
    p[9] = flag;
    D_80190CF8[p[0]]((void *)p);
}
