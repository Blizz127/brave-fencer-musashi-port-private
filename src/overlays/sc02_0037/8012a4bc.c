/* sc02_0037: func_8012A4BC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
struct BigCopy;
struct BigCopy { s32 words[41]; };
extern struct BigCopy D_80126DB8;
extern struct BigCopy D_80114EE8;
extern u8 D_80127504;
extern u8 D_80127504;
extern struct BigCopy D_80126DB8;
extern s32 D_801151D4;
extern s32 D_801151D4;
extern struct BigCopy D_80114EE8;
extern s32 D_801151D4;
extern s32 D_801151D4;
extern struct BigCopy D_80126DB8;
extern struct BigCopy D_80114EE8;
extern u8 D_80127504;

void func_8012A4BC(void) {
    D_80126DB8 = *(struct BigCopy *)D_801151D4;
    *(struct BigCopy *)D_801151D4 = D_80114EE8;
    D_80127504 = 0x30;
}
