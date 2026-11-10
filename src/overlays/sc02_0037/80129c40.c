/* sc02_0037: func_80129C40 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
struct BigCopy;
struct BigCopy { s32 words[41]; };
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern struct BigCopy D_80126DB8;
extern u8 D_80126948[];
extern struct BigCopy D_80114EE8;
extern s32 D_80126E60[];
extern s8 D_801150D6;
extern s8 D_801152C0;
extern u8 D_80127504;
extern void func_80016714(void *a0, s32 a1);
extern void func_800144D4(void);

void func_80129C40(s32 _arg0)
{
    func_80016714(((u8 *)&D_80126DB8), 0xA4);
    func_80016714(D_80126948, 0xA4);
    func_80016714(((u8 *)&D_80114EE8), 0xA4);
    func_80016714(((u8 *)&D_80114EE8) + 0xA4, 0xA4);
    func_80016714(((u8 *)&D_80114EE8) + 0x148, 0xA4);
    func_80016714(((u8 *)D_80126E60), 0xA4);
    func_80016714(((u8 *)D_80126E60) + 0xA4, 0xA4);
    func_80016714(((u8 *)D_80126E60) + 0x148, 0xA4);
    D_801150D6 = 0;
    D_801152C0 = 0;
    (*(s8 *)&D_80127504) = 0;
    func_800144D4();
}
