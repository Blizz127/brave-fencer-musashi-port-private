/* sc03_0001: func_80188ED0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80188830.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_8012F214(s32 arg0, s32 arg1, s32 arg2);

void func_80188ED0(void) {
    extern s32 D_801C0BB8;
    extern s32 D_801EF3EC;
    s32 a0;
    u16 buffer[4];
    s32 val;
    s32 *p;
    func_8012F214(a0, (s32)&D_801C0BB8, (s32)buffer);
    val = buffer[0] | (((s16)buffer[2]) << 16);
    p = *(s32**)&D_801EF3EC;
    p[1] = val;
}
