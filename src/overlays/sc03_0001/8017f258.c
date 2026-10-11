/* sc03_0001: func_8017F258 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 (*D_801918A4[])(void);
extern s32 D_801EEAE8;
extern void func_8017F2AC(u16 *a0, s32 a1);
void func_8017F2AC(u16 *a0, s32 a1);

void func_8017F258(s32 arg0)
{
    s32 v0;
    v0 = D_801918A4[arg0]();
    if (v0 != -1) {
        func_8017F2AC((u16 *)D_801EEAE8, v0);
    }
}
