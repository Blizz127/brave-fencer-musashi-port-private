/* sc01_0077: func_8013ED6C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern unsigned short D_80115112;
extern u16 D_8011511E;
extern unsigned short D_80115112;
extern u16 D_8011511A;
extern unsigned short D_80115112;
void func_8013E958();
extern s32 func_80141C50(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern void func_8013E958(void);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern unsigned short D_80115112;
extern s32 func_80141C50(void);
extern s32 func_8013F350(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern void func_8013E958(void);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern unsigned short D_80115112;
extern s32 func_80141C50(void);
extern s32 func_8013F350(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern void func_8013E958(void);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern u16 D_80115112;
s32 func_8013F350(void);
void func_8013FAF8(s16 arg0, s16 arg1);
s32 func_80141C50(void);

void func_8013ED6C(void) {
    s32 sp10[2];
    if ((s16)func_80141C50() == 0) {
        D_801151D0 = *(s32 *)&D_801151C8[(u16)D_800B9A02 * 4];
        func_8013F350();
        func_8013FAF8(7, 8);
        if (D_8011511A == 7) {
            if ((D_8011511E & 0x810) == 0) {
                return;
            }
        }
        func_8013E958();
        D_80115112 = 4;
    }
    (void)sp10;
}
