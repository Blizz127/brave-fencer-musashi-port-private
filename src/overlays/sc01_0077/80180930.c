/* sc01_0077: func_80180930 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern void func_800183E0(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern u32 D_801DA9AC;
extern u16 D_8018AA2C[];
extern u16 D_801DA9E8[];
extern s32 D_8018AA4C;
extern void func_800183E0(s32 a0);

void func_80180930(void)
{
    u32 i;
    u16 *p;
    u32 base;
    u16 *tbl;
    i = 0;
    tbl = D_8018AA2C;
    base = D_801DA9AC >> 8;
    p = D_801DA9E8;
    do {
        *p = tbl[(base + i) & 0xF] | 0x8000;
        i = i + 1;
        p = p + 1;
    } while (i < 0x10);
    func_800183E0((s32)&D_8018AA4C);
    D_801DA9AC = D_801DA9AC + 0x100;
}
